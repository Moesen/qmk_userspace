keymap-name := "moesen"
keyboard-name := "splitkb/kyria/rev3"
kyria3flags := "-e CONVERT_TO=liatris"



default:
    just --list

flash *flags="":
    qmk flash -kb {{keyboard-name}} -km {{keymap-name}} {{kyria3flags}} {{flags}}

compile *flags="":
    qmk compile -kb {{keyboard-name}} -km {{keymap-name}} {{flags}}

generate-keymap:
    qmk c2json ./keyboards/{{keyboard-name}}/keymaps/{{keymap-name}}/keymap.c --no-cpp | keymap parse -c 10 -q -

save-keymap-yaml:
    just generate-keymap > docs/keymap.yaml
    sed -i 's/layout_name: LAYOUT/layout_name: LAYOUT_split_3x6_5/' docs/keymap.yaml

draw-keymap: save-keymap-yaml
    keymap draw docs/keymap.yaml > docs/keymap.svg

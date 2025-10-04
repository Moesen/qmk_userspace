kyria3flags := "-kb splitkb/kyria/rev3 -km moesen -e CONVERT_TO=liatris"
flash:
    qmk flash {{kyria3flags}}
compile:
    qmk compile {{kyria3flags}}

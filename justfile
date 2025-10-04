kyria3flags := "-kb splitkb/kyria/rev3 -km moesen -e CONVERT_TO=liatris"
flash *flags="":
    qmk flash {{kyria3flags}} {{flags}}
compile *flags="":
    qmk compile {{kyria3flags}} {{flags}}

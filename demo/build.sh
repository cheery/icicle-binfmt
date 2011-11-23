CFLAGS="
    --std=c99
    -nostdlib
    -nostdinc
    -nostartfiles
    -nodefaultlibs
    -I../include/
    -c
    -fPIC
"

OBJECTS="
    load.o
"

gcc load.c $CFLAGS
ld -T ../prog.ld $OBJECTS -o ../demo.prog

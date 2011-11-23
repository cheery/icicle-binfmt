CFLAGS="
    --std=c99
    -I../include/
"

INTERFACES=$(ls ../interfaces-linux-x64/*.o)

gcc load.c $CFLAGS $INTERFACES -o ../load

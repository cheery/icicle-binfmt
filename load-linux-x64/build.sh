CFLAGS="
    --std=c99
    -I../include/
"

gcc load.c $CFLAGS -o ../load

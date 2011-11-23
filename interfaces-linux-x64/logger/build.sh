CFLAGS="
    --std=c99
    -I../../include
"
gcc -c logger.c $CFLAGS -o ../logger.o

cp logger.h ../../include

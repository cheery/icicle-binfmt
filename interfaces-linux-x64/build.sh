CFLAGS="
    --std=c99
    -I../include
    -c
"
cd logger
echo building logger
sh build.sh
cd ..

echo 'building require()'
gcc -c require.c -o require.o

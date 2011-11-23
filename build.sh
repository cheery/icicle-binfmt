cd interfaces-linux-x64
echo building interfaces
sh build.sh
cd ..
cd load-linux-x64
echo building loader
sh build.sh
cd ..
cd demo
echo building demo
sh build.sh
cd ..

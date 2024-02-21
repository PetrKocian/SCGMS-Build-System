cd ~/emsdk
source ./emsdk_env.sh
cd -

mkdir -p build >/dev/null 2>&1
cd build
emcmake cmake ..
emmake make

cp scgms.js ~/Desktop/webpage_test
cp scgms.wasm ~/Desktop/webpage_test
cp scgms.worker.js ~/Desktop/webpage_test

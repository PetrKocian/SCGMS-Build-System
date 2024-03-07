
if [ $# -eq 0 ]; then
    echo "ARCH=\"\"" > docker/architecture 
elif [ $# -eq 1 ]; then
    echo "ARCH=\"$1\"" > docker/architecture 
else
    echo "ARCH=\"\"" > docker/architecture 
fi

docker run -it -v $(pwd):/src wasm-builder


if [ $# -eq 0 ]; then
    echo "ARCH=\"\"" > docker_env/architecture 
elif [ $# -eq 1 ]; then
    echo "ARCH=\"$1\"" > docker_env/architecture 
else
    echo "ARCH=\"\"" > docker_env/architecture 
fi

docker run -it -v $(pwd):/src wasm-builder-env

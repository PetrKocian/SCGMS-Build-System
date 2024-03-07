cd /src
. docker_env/architecture
python3 prepare_build.py $ARCH
chmod -R a+rwx build_dir

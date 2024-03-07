FROM ubuntu:20.04

ARG WORKSPACE_DIR=/workspace

ENV DEBIAN_FRONTEND noninteractive

# Prepare for the installation of external repositories
RUN set -uex; \
    apt-get update ; \
    apt-get -y install gnupg software-properties-common ca-certificates curl apt-transport-https ; \
    mkdir -p /etc/apt/keyrings

RUN apt-get -y install build-essential

RUN apt-get -y install python3 python3-pip

RUN pip install GitPython

RUN apt-get -y install git

RUN apt-get -y install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0

CMD /src/docker_env/script.sh

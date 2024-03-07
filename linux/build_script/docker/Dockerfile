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

CMD /src/docker/script.sh

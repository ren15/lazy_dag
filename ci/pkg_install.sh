set -xe

export DEBIAN_FRONTEND=noninteractive

apt-get update 

apt-get install -y \
    sudo \
    python3 python3-pip \
    ninja-build \
    build-essential \
    cmake \
    make \
    gcc g++ \
    clang clang-tidy clangd \
    curl zip unzip tar \
    pkg-config \
    git zsh

pip install conan 

set -xe
export DEBIAN_FRONTEND=noninteractive

apt-get update 

apt-get install -y \
    build-essential \
    python3 python3-pip \
    ninja-build \
    cmake \
    make \
    gcc \
    clang clang-tidy clangd \
    curl zip unzip tar \
    pkg-config \
    git

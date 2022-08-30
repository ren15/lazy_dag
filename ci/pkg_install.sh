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

# install mold
mkdir /dep_build
pushd /dep_build
git clone https://github.com/rui314/mold.git
cd mold
git checkout v1.4.1
bash install-build-deps.sh
make -j$(nproc) CXX=clang++ CC=clang
make install
popd



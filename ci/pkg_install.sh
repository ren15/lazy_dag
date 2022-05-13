set -xe
export DEBIAN_FRONTEND=noninteractive

if [[ -z "${CI_i}" ]]; then
    echo "Not in CI, setting China mirror"
    sed -i 's/archive.ubuntu.com/mirrors.ustc.edu.cn/g' /etc/apt/sources.list
    sed -i 's/security.ubuntu.com/mirrors.ustc.edu.cn/g' /etc/apt/sources.list
fi

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
    git


if [[ -z "${CI_i}" ]]; then
    echo "Not in CI, using China mirror"
    pip install -i https://pypi.tuna.tsinghua.edu.cn/simple conan
else
    echo "in CI, install directly"
    pip install conan
fi


#curl https://sh.rustup.rs -sSf | sh -s -- -y

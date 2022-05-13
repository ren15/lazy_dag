set -xe

mkdir -p /home/${USER}
chown $UID_i:$GID_i /home/${USER}

export DEBIAN_FRONTEND=noninteractive

if [[ -z "${GITHUB_ACTIONS}" ]]; then
    echo "Not in CI, setting China mirror"
    sed -i 's/archive.ubuntu.com/mirrors.ustc.edu.cn/g' /etc/apt/sources.list
    sed -i 's/security.ubuntu.com/mirrors.ustc.edu.cn/g' /etc/apt/sources.list
fi

apt-get update 1>/dev/null

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
    git zsh \
    1>/dev/null


if [[ -z "${GITHUB_ACTIONS}" ]]; then
    echo "Not in CI, using China mirror"
    pip install -i https://pypi.tuna.tsinghua.edu.cn/simple conan 1>/dev/null
else
    echo "in CI, install directly"
    pip install conan 1>/dev/null
fi


#curl https://sh.rustup.rs -sSf | sh -s -- -y

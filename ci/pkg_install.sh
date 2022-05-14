set -xe

mkdir -p /home/${USER}
chown $UID_i:$GID_i /home/${USER}

export DEBIAN_FRONTEND=noninteractive

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

apt-get clean && rm -rf /var/lib/apt/lists/*

pip install conan 1>/dev/null


#curl https://sh.rustup.rs -sSf | sh -s -- -y

mkdir -p app
sudo rm -rf app/*
sudo chmod g+s app

rsync -ah ./ app --exclude "app"

docker build -t cpp_env:latest .

docker run --rm \
    -v ${PWD}/app:/app \
    -w /app \
    -m 6g \
    cpp_env:latest \
    bash -c "
    which mold
    mold --version
    make dep_build
    make configure
    make build
    make run 
    make bench"

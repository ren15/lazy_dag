docker build -t cpp_env:latest .

mkdir -p app
sudo rm -rf app/*

rsync -ah ./ app --exclude "app"

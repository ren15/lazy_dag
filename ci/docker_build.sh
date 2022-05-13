USER=$(whoami)
UID_i=$(id -u)
GID_i=$(id -g)

docker build \
	--build-arg USER=${USER} \
	--build-arg UID_i=${UID_i} \
	--build-arg GID_i=${GID_i} \
	-t cpp_env .
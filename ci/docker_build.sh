USER=$(whoami)
UID_i=$(id -u)
GID_i=$(id -g)
CI_i=${GITHUB_ACTIONS}
echo "checking if in CI: CI_i=${CI_i}"

docker build \
	--build-arg USER=${USER} \
	--build-arg UID_i=${UID_i} \
	--build-arg GID_i=${GID_i} \
	--build-arg CI_i=${CI_i} \
	-t cpp_env .
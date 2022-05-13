mkdir -p ${PWD}/.conan
docker run --rm \
    --privileged \
    --hostname repo_env \
    --user $(id -u):$(id -g) \
    --net=host \
    -v /etc/passwd:/etc/passwd:ro -v /etc/group:/etc/group:ro \
    -v /etc/localtime:/etc/localtime:ro \
    -v ${PWD}:/app -w /app \
    -v ${PWD}/.conan:/home/$(whoami)/.conan \
    -e http_proxy=${http_proxy} \
    -e https_proxy=${https_proxy} \
    -e PWD=/app \
    cpp_env $@
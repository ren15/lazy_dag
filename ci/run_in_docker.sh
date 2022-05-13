mkdir -p ${PWD}/.conan

if [[ -z "${GITHUB_ACTIONS}" ]]; then
    echo "Not in CI, use docker run -it"
    DOCKER_IT_ARG="-it"
fi

docker run --rm ${DOCKER_IT_ARG} \
    --privileged \
    --hostname cpp_env \
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
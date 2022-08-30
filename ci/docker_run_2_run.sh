docker run --rm \
    -v ${PWD}/app:/app \
    -w /app \
    -m 6g \
    cpp_env:latest \
    bash -c "
    make run
    make bench
    "

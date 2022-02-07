file(GLOB srcs *.cpp)

set(TARGET_NAME mathop_bench)

add_executable(${TARGET_NAME}
${srcs}
)

target_link_libraries(${TARGET_NAME}
pthread
benchmark::benchmark benchmark::benchmark_main
)


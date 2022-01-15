file(GLOB srcs *.cpp)

set(TARGET_NAME mathop_bench)

add_executable(${TARGET_NAME}
${srcs}
)

target_include_directories(${TARGET_NAME} 
BEFORE PRIVATE "${BENCHMARK_FOLDER}/include"
)

target_link_libraries(${TARGET_NAME}
${CONAN_LIBS}
${BENCHMARK_LIBRARY}
pthread
)


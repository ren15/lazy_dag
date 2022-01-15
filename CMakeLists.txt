cmake_minimum_required(VERSION 3.15)
project(expression_template_benchmark)

include(cmake/cxx_setting.cmake)
include(cmake/support_libs.cmake)

# --------------------------------------

file(GLOB srcs src/*.cpp)

add_executable(et-bench 
${srcs}
)

target_include_directories(et-bench 
BEFORE PRIVATE "${BENCHMARK_FOLDER}/include"
)

target_link_libraries(et-bench
${CONAN_LIBS}
${BENCHMARK_LIBRARY}
pthread
)

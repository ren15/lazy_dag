cmake_minimum_required(VERSION 3.15)
project(expression_template_benchmark)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

IF(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(NO_OUTPUT_DIRS)
ENDIF()

add_executable(et-bench 
src/main.cpp
)

target_include_directories(et-bench PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/include
)

target_link_libraries(et-bench
${CONAN_LIBS}
)
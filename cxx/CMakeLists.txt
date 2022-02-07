cmake_minimum_required(VERSION 3.15)
project(expression_template_benchmark)

include(cmake/cxx_setting.cmake)
include(cmake/support_libs.cmake)

# --------------------------------------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(benchmark CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_subdirectory(src/math_op_bench)

add_subdirectory(src/AAD)

add_subdirectory(src/ranges_impl)


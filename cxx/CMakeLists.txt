cmake_minimum_required(VERSION 3.15)
project(expression_template_benchmark)

include(cmake/cxx_setting.cmake)
include(cmake/support_libs.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# For building on macOS
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(benchmark CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)

add_subdirectory(src/math_op_bench)

add_subdirectory(src/AAD)

add_subdirectory(src/ranges_impl)


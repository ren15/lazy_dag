cmake_minimum_required(VERSION 3.15)
project(expression_template_benchmark)

include(cmake/cxx_setting.cmake)
include(cmake/support_libs.cmake)

# --------------------------------------


add_subdirectory(src/math_op_bench)

add_subdirectory(src/AAD)


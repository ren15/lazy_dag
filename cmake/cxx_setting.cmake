set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_FLAGS "-O3 -march=native ${CMAKE_C_FLAGS}")
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wshadow -Wpedantic -fsanitize=undefined,address ${CMAKE_C_FLAGS}")


set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")


set(target_name range_lazy_prime)
add_executable(${target_name}
range_lazy_prime.cpp
)
target_link_libraries(${target_name}
${CONAN_LIBS}
${BENCHMARK_LIBRARY}
pthread
)

# ===============================================================================
add_executable(ranges_impl_1
main.cpp
ranges_example.cpp
)

target_link_libraries(ranges_impl_1
${CONAN_LIBS}
)

# =============================================================================
add_executable(ranges_impl_bench
bench.cpp
)

target_include_directories(ranges_impl_bench
BEFORE PRIVATE "${BENCHMARK_FOLDER}/include"
)

target_link_libraries(ranges_impl_bench
${CONAN_LIBS}
${BENCHMARK_LIBRARY}
pthread
)



set(target_name range_lazy_prime)

add_executable(${target_name}
range_lazy_prime.cpp
)

target_link_libraries(${target_name} PRIVATE 
${CONAN_LIBS}
pthread
)

# ===============================================================================
add_executable(ranges_impl_1
main.cpp
ranges_example.cpp
)

target_link_libraries(ranges_impl_1 PRIVATE 
${CONAN_LIBS}
)

# =============================================================================
add_executable(ranges_impl_bench
bench.cpp
)

target_link_libraries(ranges_impl_bench PRIVATE 
benchmark::benchmark benchmark::benchmark_main
pthread
)



# target_link_libraries(dag_bench
# ${CONAN_LIBS}
# ${BENCHMARK_LIBRARY}
# pthread
# )

add_executable(range_impl_1
range_impl_1.cpp
)
target_link_libraries(range_impl_1
${CONAN_LIBS}
)

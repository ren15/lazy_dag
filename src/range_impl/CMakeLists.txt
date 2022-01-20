
# target_link_libraries(dag_bench
# ${CONAN_LIBS}
# ${BENCHMARK_LIBRARY}
# pthread
# )

add_executable(ranges_impl_1
main.cpp
ranges_example.cpp
)

target_link_libraries(ranges_impl_1
${CONAN_LIBS}
)

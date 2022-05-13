file(GLOB srcs *.cpp)

add_executable(dag_pointer
dag_pointer.cpp
)

add_executable(dag_tape
dag_tape.cpp
)

add_executable(dag_template
dag_template.cpp
)

add_executable(AAD_toy_c15s2
toyCodeChp15section2.cpp
)

add_executable(dag_bench
bench.cpp
)


target_link_libraries(dag_bench PRIVATE
benchmark::benchmark benchmark::benchmark_main
pthread
)


add_executable(dag_range
dag_range.cpp
)

target_link_libraries(dag_range PRIVATE 
fmt
# range-v3
${CONAN_LIBS}
)

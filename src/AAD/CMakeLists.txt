file(GLOB srcs *.cpp)

add_executable(dag_pointer
dag_pointer.cpp
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

target_include_directories(dag_bench
BEFORE PRIVATE "${BENCHMARK_FOLDER}/include"
)

target_link_libraries(dag_bench
${CONAN_LIBS}
${BENCHMARK_LIBRARY}
pthread
)

add_executable(dag_range
dag_range.cpp
)

target_link_libraries(dag_bench
${CONAN_LIBS}
)
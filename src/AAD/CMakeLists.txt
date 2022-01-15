file(GLOB srcs *.cpp)

set(TARGET_NAME AAD_toy_c9s5)

add_executable(AAD_toy_c9s5
toyCodeChp9section5.cpp
)

# target_include_directories(${TARGET_NAME} 
# BEFORE PRIVATE "${BENCHMARK_FOLDER}/include"
# )

# target_link_libraries(${TARGET_NAME}
# ${CONAN_LIBS}
# ${BENCHMARK_LIBRARY}
# pthread
# )


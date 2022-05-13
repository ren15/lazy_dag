mkdir -p ${DEP_DIR}
cd ${DEP_DIR}
git clone https://github.com/google/benchmark.git
# git clone https://github.com/ericniebler/range-v3.git
git clone https://github.com/asavine/CompFinance.git

# setup gbench 
cd ${DEP_DIR}/benchmark
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release \
    -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on \
	-DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_DIR} \
    -S . -B "build" 
cmake --build "build" --config Release -j
cd build
cmake --install . --prefix ${CMAKE_PREFIX_DIR} 

# setup range-v3
cd ${DEP_DIR}/range-v3
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_DIR} \
    -S . -B "build"
cmake --build "build" -j6
cd build
cmake --install . --prefix ${CMAKE_PREFIX_DIR} 
git clone https://github.com/google/benchmark.git
cd benchmark
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -S . -B "build"
cmake --build "build" --config Release -j
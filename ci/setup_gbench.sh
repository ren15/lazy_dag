git clone https://github.com/google/benchmark.git
cd benchmark
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"
cmake --build "build" --config Release
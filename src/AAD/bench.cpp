#include "dag_pointer.hpp"

// #include "dag_template.hpp"

#include <benchmark/benchmark.h>

static void BM_pointer(benchmark::State& state)
{
    for (auto _ : state) {
        // benchmark::DoNotOptimize(expesssion_template::op(1, 2));
    }
}
BENCHMARK(BM_pointer);

BENCHMARK_MAIN();
#include <benchmark/benchmark.h>

#include "math_op.hpp"

#define BENCH_OP(op)                                                 \
    static void BM_##op(benchmark::State& state)                     \
    {                                                                \
        for (auto _ : state) {                                       \
            benchmark::DoNotOptimize(expesssion_template::op(1, 2)); \
        }                                                            \
    }                                                                \
    BENCHMARK(BM_##op);

BENCH_OP(add);

BENCHMARK_MAIN();
#include <benchmark/benchmark.h>

#include "math_op.hpp"

static void BM_Add(benchmark::State& state)
{
    for (auto _ : state) {
        expesssion_template::add(1, 2);
    }
}
BENCHMARK(BM_Add);

static void BM_Minus(benchmark::State& state)
{
    for (auto _ : state) {
        expesssion_template::minus(1, 2);
    }
}
BENCHMARK(BM_Minus);

static void BM_Multiply(benchmark::State& state)
{
    for (auto _ : state) {
        expesssion_template::multiply(1, 2);
    }
}
BENCHMARK(BM_Multiply);

static void BM_Divide(benchmark::State& state)
{
    for (auto _ : state) {
        expesssion_template::divide(1, 2);
    }
}
BENCHMARK(BM_Divide);

BENCHMARK_MAIN();
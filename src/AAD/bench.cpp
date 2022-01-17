#include "dag_pointer.hpp"
#include "dag_template.hpp"

#include <benchmark/benchmark.h>

#include <cassert>
#include <iostream>

static void BM_pointer(benchmark::State& state)
{
    using DAG_pointer::Number;
    Number x[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    Number y = DAG_pointer::f(x);
    y.setOrder();
    for (auto _ : state) {
        benchmark::DoNotOptimize(y.evaluate());
    }
}
BENCHMARK(BM_pointer);

static void BM_template(benchmark::State& state)
{
    using DAG_template::Number;
    Number x[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    Number y = DAG_template::f(x);

    for (auto _ : state) {
        benchmark::DoNotOptimize(y.getVal());
    }
}
BENCHMARK(BM_template);

static void BM_assert_equal(benchmark::State& state)
{

    auto template_result = []() {
        DAG_template::Number x[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
        DAG_template::Number y = DAG_template::f(x);
        return y.getVal();
    };

    auto pointer_result = []() {
        DAG_pointer::Number x[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
        DAG_pointer::Number y = DAG_pointer::f(x);
        return y.evaluate();
    };

    assert(template_result == pointer_result);

    for (auto _ : state) {
    }
}
BENCHMARK(BM_assert_equal);

BENCHMARK_MAIN();
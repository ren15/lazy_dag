#include "dag_handwritten.hpp"
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

static void BM_handwritten(benchmark::State& state)
{
    auto v = std::vector<double>();
    for (int i = 0; i < 5; i++) {
        v.push_back(i + 1);
    }

    auto x = std::array<double, 5>();
    for (int i = 0; i < 5; i++) {
        x[i] = v[i];
    }

    for (auto _ : state) {
        benchmark::DoNotOptimize(DAG_handwritten::Number::getVal(x));
    }
}
BENCHMARK(BM_handwritten);

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

    auto handwritten_result = []() {
        std::array x = { 1.0, 2.0, 3.0, 4.0, 5.0 };
        return DAG_handwritten::Number::getVal(x);
    };

    assert(template_result == pointer_result);
    assert(handwritten_result == pointer_result);

    for (auto _ : state) {
    }
}
BENCHMARK(BM_assert_equal);

BENCHMARK_MAIN();
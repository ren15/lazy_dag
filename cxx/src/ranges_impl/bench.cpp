#include "lazy_prime.hpp"
#include "vec.hpp"

#include <benchmark/benchmark.h>
#include <bits/stdint-uintn.h>
#include <cstdio>
#include <fmt/core.h>
#include <range/v3/all.hpp>

#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

// static void BM_v_add_s(benchmark::State& state)
// {
//     auto v2 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     for (auto _ : state) {
//         auto v3 = v2 + 2LL;
//         benchmark::DoNotOptimize(v3);
//     }
// }
// BENCHMARK(BM_v_add_s);

// static void BM_v_add_2s(benchmark::State& state)
// {
//     auto v2 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     for (auto _ : state) {
//         auto v3 = v2 + 2LL + 3LL;
//         benchmark::DoNotOptimize(v3);
//     }
// }
// BENCHMARK(BM_v_add_2s);

// static void BM_v_add_v(benchmark::State& state)
// {
//     auto v2 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     auto v3 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     for (auto _ : state) {
//         auto v4 = v2 + 2LL;
//         benchmark::DoNotOptimize(v4);
//     }
// }
// BENCHMARK(BM_v_add_v);

// static void BM_v_multiply_v(benchmark::State& state)
// {
//     auto v2 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     auto v3 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     for (auto _ : state) {
//         auto v4 = v2 * v3;
//         benchmark::DoNotOptimize(v4);
//     }
// }
// BENCHMARK(BM_v_multiply_v);

// static void BM_linear(benchmark::State& state)
// {
//     auto v2 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     auto v3 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     for (auto _ : state) {
//         auto v4 = v2 * v3 + 3LL * v2 + 4LL + v3;
//         benchmark::DoNotOptimize(v4);
//     }
// }
// BENCHMARK(BM_linear);

// static void BM_linear_hand(benchmark::State& state)
// {
//     auto v2 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     auto v3 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);

//     for (auto _ : state) {
//         auto temp = RangeImpl::Vec<long long>::zeros(v2.size());
//         for (size_t i = 0; i < v2.size(); i++) {
//             temp[i] = v2[i] * v3[i] + 3LL * v2[i] + 4LL + v3[i];
//         }

//         benchmark::DoNotOptimize(temp);
//     }
// }
// BENCHMARK(BM_linear_hand);

// static void BM_sum(benchmark::State& state)
// {
//     auto v2 = RangeImpl::Vec<long long>::iota(1LL, 100001LL);
//     for (auto _ : state) {
//         auto sum_value = v2.sum();
//         benchmark::DoNotOptimize(sum_value);
//     }
// }
// BENCHMARK(BM_sum);

static void BM_lazyprime(benchmark::State& state)
{
    uint64_t start = 1000000;
    int cnt = 2000;
    for (auto _ : state) {
        auto ans = lazy_prime::get_prime_vec(start, cnt);
        benchmark::DoNotOptimize(ans);
    }
}
BENCHMARK(BM_lazyprime);

static void BM_lazyprime_eager(benchmark::State& state)
{
    uint64_t start = 1000000;
    int cnt = 2000;
    for (auto _ : state) {
        auto ans = lazy_prime::get_prime_vec_eager(start, cnt);
        benchmark::DoNotOptimize(ans);
    }
}
BENCHMARK(BM_lazyprime_eager);

BENCHMARK_MAIN();
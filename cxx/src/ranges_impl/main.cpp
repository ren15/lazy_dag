
#include "vec.hpp"

#include <fmt/core.h>

void vec_usage()
{
    auto v2 = RangeImpl::Vec<long long>::iota(1LL, 1001LL);
    fmt::print("v2.sum() = {}\n", v2.sum());
    auto v3 = v2 + 1LL;
    fmt::print("v3.sum() = {}\n", v3.sum());
}

auto main() -> int
{
    // ranges_example();
    vec_usage();
}
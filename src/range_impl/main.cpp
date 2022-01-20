/*

To illustrate lazy evaluation,

Vector<int,10000> v;

ans = v * 10 * 20 * 30 * 40;

If vector * scaler takes 1 ms,
the naive approach takes 4 ms,
but the lazy approach takes only 1 ms.

TODO:

Check vec.hpp

1. Implement operator* for Vector<T,N> as eager evaluation.

2. Use ranges to implement operator* for Vector<T,N> as lazy evaluation.

*/

#include "vec.hpp"

#include <fmt/core.h>
#include <range/v3/all.hpp>

#include <iostream>
#include <utility>
#include <vector>

void ranges_example();


void vec_usage()
{
    auto v2 = RangeImpl::Vec<int>::iota(20L, 30L);
    v2.print();
}

int main()
{
    // ranges_example();
    vec_usage();
}
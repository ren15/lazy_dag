/*

To illustrate lazy evaluation,

Vector<int,10000> v;

ans = v * 10 * 20 * 30 * 40;

If vector * scaler takes 1 ms,
the naive approach takes 4 ms,
but the lazy approach takes only 1 ms.


TODO:
1. Implement operator* for Vector<T,N> as eager evaluation.

2. Use ranges to implement operator* for Vector<T,N> as lazy evaluation.

*/




#include <range/v3/all.hpp>
#include <fmt/core.h>

#include <iostream>
#include <utility>
#include <vector>

int main()
{
    {
        using ranges::views::transform;
        std::vector<int> elements = { -1, 0, 1 };
        auto add_one_view = elements | transform([](int _next) { return _next + 1; });

        std::cout << add_one_view;
    }
    {
        using ranges::single_view;
        using ranges::views::transform;
        using ranges::views::zip_with;

        fmt::print("\n-------- {} --------\n", "zip_with");

        int left = 1;
        double right = 40.0;
        auto expr = zip_with(std::plus<> {}, single_view { left }, single_view { right });
        // print [41]
        std::cout << expr << std::endl;

        short next_value = 1;
        auto expr2 = zip_with(std::plus<> {}, expr, single_view { next_value });

        // print [42]
        std::cout << expr2 << std::endl;
    }
    {
        // row-major
        using Matrix = std::vector<std::vector<double>>;

        // column vector
        using Vector = std::vector<double>;

        using ranges::inner_product;
        using ranges::views::transform;

        Matrix A = { { 1, 2, 3 },
            { 4, 5, 6 } };
        Vector x = { 7, 8, 9 };

        auto product = A | transform([&x](const auto& row) {
            return inner_product(row, x, 0.0);
        });

        // print [50,122]
        std::cout << product;
    }
}
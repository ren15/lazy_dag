#include "dag_range.hpp"

#include <range/v3/all.hpp>

#include <iostream>
#include <utility>
#include <vector>

int main()
{
    using ranges::single_view;
    using ranges::views::transform;
    using ranges::views::zip_with;

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
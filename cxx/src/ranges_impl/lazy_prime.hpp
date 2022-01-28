#include <range/v3/all.hpp>

#include <algorithm>
#include <vector>

namespace lazy_prime {

namespace views = ranges::views;
namespace actions = ranges::actions;

template <typename T>
auto get_prime_vec(T start, int cnt) -> std::vector<T>
{
    auto isPrime = [](auto i) {
        for (auto j = 2; j * j <= i; ++j) {
            if (i % j == 0)
                return false;
        }
        return true;
    };

    auto odd = [](auto i) { return i % 2 == 1; };

    auto result = std::vector<T> {};
    result.reserve(cnt);

    for (auto i : views::iota(start)
            | views::filter(isPrime)
            | views::filter(odd)
            | views::take(cnt)) {
        result.push_back(i);
    }
    ranges::reverse(result);
    return result;
}

template <typename T>
auto get_prime_vec_eager(T start, int cnt) -> std::vector<T>
{
    auto isPrime = [](auto i) {
        for (auto j = 2; j * j <= i; ++j) {
            if (i % j == 0)
                return false;
        }
        return true;
    };
    auto odd = [](auto i) { return i % 2 == 1; };

    auto result = std::vector<T> {};
    result.reserve(cnt);

    for (T i = start;; i += 2) {
        if (!odd(i)) {
            i++;
        }
        if (isPrime(i)) {
            result.push_back(i);
            if (result.size() == cnt)
                break;
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}
};
#include <range/v3/all.hpp>

#include <vector>

namespace lazy_prime {

namespace views = ranges::views;

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

    for (auto i : views::iota(start) | views::filter(odd)
            | views::filter(isPrime) | views::take(cnt)) {
        result.push_back(i);
    }
    return result;
    // return std::move(result);
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
    return result;
    // return std::move(result);
}
};
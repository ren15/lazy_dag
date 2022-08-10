#include <range/v3/all.hpp>

#include <iostream>
#include <vector>

namespace views = ranges::views;

int main()
{
    {
        std::cout << std::boolalpha;

        std::vector<int> vec;
        std::vector<int> vec2;

        for (auto i : views::iota(0, 10))
            vec.push_back(i); // (1)

        for (auto i : views::iota(0) | views::take(10))
            vec2.push_back(i); // (2)

        std::cout << "vec == vec2: " << (vec == vec2) << '\n'; // true

        for (int i : vec)
            std::cout << i << " "; // 0 1 2 3 4 5 6 7 8 9
    }

    {
        auto isPrime = [](int i) {
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0)
                    return false;
            }
            return true;
        };
        auto odd = [](int i) { return i % 2 == 1; };

        std::cout << "Numbers from 1000000 to 1001000 (dispayed each 100th): " << std::endl;
        for (int i : views::iota(1000000, 1001000)) {
            if (i % 100 == 0)
                std::cout << i << " ";
        }

        std::cout << "\n\n";
        std::cout << "Odd numbers from 1000000 to 1001000 (displayed each 100th): " << std::endl;
        for (int i : views::iota(1000000, 1001000) | views::filter(odd)) {
            if (i % 100 == 1)
                std::cout << i << " ";
        }

        std::cout << "\n\n";
        std::cout << "Prime numbers from 1000000 to 1001000: " << std::endl;
        for (int i : views::iota(1000000, 1001000) | views::filter(odd) | views::filter(isPrime)) {
            std::cout << i << " ";
        }

        std::cout << "\n\n";
        std::cout << "20 prime numbers starting with 1000000: " << std::endl;
        for (int i : views::iota(1000000) | views::filter(odd) | views::filter(isPrime) | views::take(20)) {
            std::cout << i << " ";
        }
    }
}
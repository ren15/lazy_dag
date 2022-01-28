
#include <range/v3/all.hpp>

#include <iostream>
#include <numeric>
#include <vector>

bool isPrime(int i)
{
    for (int j = 2; j * j <= i; ++j) {
        if (i % j == 0)
            return false;
    }
    return true;
}

int main()
{
    {
        std::cout << std::boolalpha;

        std::vector<int> vec;
        std::vector<int> vec2;

        for (int i : ranges::views::iota(0, 10))
            vec.push_back(i); // (1)

        for (int i : ranges::views::iota(0) | ranges::views::take(10))
            vec2.push_back(i); // (2)

        std::cout << "vec == vec2: " << (vec == vec2) << '\n'; // true

        for (int i : vec)
            std::cout << i << " "; // 0 1 2 3 4 5 6 7 8 9
    }

    {
        std::cout << "Numbers from 1000000 to 1001000 (dispayed each 100th): " << std::endl;
        for (int i : ranges::views::iota(1000000, 1001000)) {
            if (i % 100 == 0)
                std::cout << i << " ";
        }

        std::cout << "\n\n";
        // (2)
        auto odd = [](int i) { return i % 2 == 1; };
        std::cout << "Odd numbers from 1000000 to 1001000 (displayed each 100th): " << std::endl;
        for (int i : ranges::views::iota(1000000, 1001000) | ranges::views::filter(odd)) {
            if (i % 100 == 1)
                std::cout << i << " ";
        }

        std::cout << "\n\n";
        // (3)
        std::cout << "Prime numbers from 1000000 to 1001000: " << std::endl;
        for (int i : ranges::views::iota(1000000, 1001000) | ranges::views::filter(odd)
                | ranges::views::filter(isPrime)) {
            std::cout << i << " ";
        }

        std::cout << "\n\n";
        // (4)
        std::cout << "20 prime numbers starting with 1000000: " << std::endl;
        for (int i : ranges::views::iota(1000000) | ranges::views::filter(odd)
                | ranges::views::filter(isPrime)
                | ranges::views::take(20)) {
            std::cout << i << " ";
        }
    }
}
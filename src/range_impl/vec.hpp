#pragma once

#include <iostream>
#include <vector>

namespace RangeImpl {
using std::vector;

template <typename T>
class Vec {

    vector<T> inner_data;

public:
    Vec(vector<T> input)
        : inner_data(input)
    {
    }
    void print() const
    {
        std::cout << "[";
        for (auto it = inner_data.begin(); it != inner_data.end(); ++it) {
            std::cout << *it;
            if (it != inner_data.end() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
    static auto zeros(size_t size) -> Vec<T>
    {
        return Vec<T>(vector<T>(size, 0));
    }
    static auto ones(size_t size) -> Vec<T>
    {
        return Vec<T>(vector<T>(size, 1));
    }
    static auto iota(T start, T end) -> Vec<T>
    {
        vector<T> v;
        for (T i = start; i < end; i++) {
            v.push_back(i);
        }
        return Vec<T>(v);
    }
};
}; // namespace RangeImpl
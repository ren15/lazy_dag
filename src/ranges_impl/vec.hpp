#pragma once

#include <iostream>
#include <vector>
#include <cassert>

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

    [[nodiscard]] auto size() const -> size_t
    {
        return inner_data.size();
    }

    auto sum() const -> T
    {
        auto temp = T { 0 };
        for (auto const& i : inner_data) {
            temp += i;
        }
        return temp;
    }

    // -------------------------------------
    auto operator[](std::size_t idx) const -> T const&
    {
        return inner_data[idx];
    }
    auto operator[](std::size_t idx) -> T&
    {
        return inner_data[idx];
    }

    // -------------------------------------
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
    // --------------------------------------
};

template <typename T>
auto operator+(Vec<T> const& lhs, Vec<T> const& rhs) -> Vec<T>
{
    assert(lhs.size() == rhs.size());
    auto temp = Vec<T>::ones(lhs.size());
    for (size_t i = 0; i < lhs.size(); i++) {
        temp[i] = lhs[i] + rhs[i];
    }
    return temp;
}
template <typename T>
auto operator*(Vec<T> const& lhs, Vec<T> const& rhs) -> Vec<T>
{
    assert(lhs.size() == rhs.size());
    auto temp = Vec<T>::ones(lhs.size());
    for (size_t i = 0; i < lhs.size(); i++) {
        temp[i] = lhs[i] * rhs[i];
    }
    return temp;
}

template <typename T>
auto operator+(T const& s, Vec<T> const& a) -> Vec<T>
{
    auto temp = Vec<T>::ones(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        temp[i] = s + a[i];
    }
    return temp;
}
template <typename T>
auto operator+(Vec<T> const& a, T const& s) -> Vec<T>
{
    return s + a;
}

template <typename T>
auto operator*(T const& s, Vec<T> const& a) -> Vec<T>
{
    auto temp = Vec<T>::ones(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        temp[i] = s * a[i];
    }
    return temp;
}
template <typename T>
auto operator*(Vec<T> const& a, T const& s) -> Vec<T>
{
    return s * a;
}

}; // namespace RangeImpl
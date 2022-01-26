#include "math_op.hpp"

#include <cmath>

namespace expesssion_template {

auto add(double a, double b) -> double { return a + b; }
auto minus(double a, double b) -> double { return a - b; }
auto multiply(double a, double b) -> double { return a * b; }
auto divide(double a, double b) -> double { return a / b; }

auto log(double a, double b) -> double { return std::log(a) / std::log(b); }
auto exp(double a, double b) -> double { return std::exp(a) / std::exp(b); }
auto pow(double a, double b) -> double { return std::pow(a, b); }
} // namespace expesssion_template
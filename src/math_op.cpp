#include "math_op.hpp"

#include <cmath>

namespace expesssion_template {

double add(double a, double b)
{
    return a + b;
}
double minus(double a, double b)
{
    return a - b;
}
double multiply(double a, double b)
{
    return a * b;
}
double divide(double a, double b)
{
    return a / b;
}

double log(double a, double b)
{
    return std::log(a) / std::log(b);
}
double exp(double a, double b)
{
    return std::exp(a) / std::exp(b);
}
double pow(double a, double b)
{
    return std::pow(a, b);
}
}
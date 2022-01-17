#include <cmath>

namespace DAG_handwritten {

class Number {
public:
    template <typename T>
    auto static getVal(T x) -> double
    {
        auto y1 = x[2] * (5.0 * x[0] + x[1]);
        auto y2 = std::log(y1);
        auto y = (y1 + x[3] * y2) * (y1 + y2);
        return y;
    }
};
}
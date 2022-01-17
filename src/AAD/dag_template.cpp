/*
        Toy code contained in chapter 9, sections 5 (pages 349 to 355).
*/

#include "dag_template.hpp"

int main()
{
    Number x[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

    // Evaluate and build the tape
    Number y = f(x);

    // Propagate adjoints through the tape in reverse order
    y.propagateAdjoints();

    // Get derivatives
    for (size_t i = 0; i < 5; ++i) {
        cout << "a" << i << " = " << x[i].adjoint() << endl;
    }

    // 950.736, 190.147, 443.677, 73.2041, 0
}

/*
        Toy code contained in chapter 9, sections 2, 3 and 4 (pages 328 to 349).

        For VS15, the code in the book compiles and reproduces the results described.
        VS17 has issues with not accepting directly created lambdas into non const refs, so the code below is modified slightly
        to work in both VS15 and VS17.
*/

#include "dag_pointer.hpp"

/******************************************************************************************************************/
int main()
{
    Number x[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

    // Build the DAG
    Number y = f(x);

    // Set the order on the DAG
    y.setOrder();

    // Log program
    y.logProgram();

    // Evaluate on the DAG
    cout << y.evaluate() << endl; // 797.751

    // Log all results
    y.logResults();

    // Uncomment the following code to evaluate the DAG with a different input (see page 336)
    /*
        // Change x0 on the DAG
        x[0].setVal(2.5);

        // Evaluate on the DAG again
        cout << y.evaluate() << endl; // 2769.76

        // Log results again
        y.logResults();*/

    y.propagateAdjoints();

    // Get derivatives
    for (size_t i = 0; i < 5; ++i) {
        cout << "a" << i << " = " << x[i].adjoint() << endl;
    }
}

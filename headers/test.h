#ifndef __TEST_H
#define __TEST_H



/**
    \brief This function tests given equation.

    It solves the equation and compares new roots and number of them
    with reference ones.
*/
int TestEquation(struct TestsStruct* test_container,
                    struct CoefficientsStruct* equation_coefficients,
                    struct RootsStruct* equation_roots,
                    const int test_number);

/**
    \brief This function starts unit tests.

    It scans users desire if they want to run tests.
    If so, it scans reference values from file and tests the programm.
*/
void UnitTests(struct CoefficientsStruct* equation_coefficients,
                struct RootsStruct* equation_roots);

#endif

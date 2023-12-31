#ifndef __IO_H
#define __IO_H

/**
    \brief This function scans 3 coefficients of the quadratic equation.

    It uses stucture to combine coefficients into group.
*/
bool GetInput(struct CoefficientsStruct* equation_coefficients);

/**
    \brief This function scans 3 coefficients of the quadratic equation from given file.

    It uses stucture to combine coefficients into group.
*/
bool GetFileInput(FILE* fp, struct CoefficientsStruct* equation_coefficients);

/**
    \brief This function scans reference values for tests from file.

    It uses structure to combine different values into group.
*/
bool GetTestFileInput(FILE* fp, struct TestsStruct* test_container);

/**
    \brief This function prints output for a wrong test.
*/
void PrintWrongTestOutput(struct TestsStruct* test_container,
                          struct RootsStruct* equation_roots,
                          const int test_number,
                          const int number_of_roots);

/**
    \brief This function prints a sentence about number of roots and prints them if exist.
*/
void PrintOutput(const TypeOfRoots number_of_roots, const struct RootsStruct* equation_roots);

#endif

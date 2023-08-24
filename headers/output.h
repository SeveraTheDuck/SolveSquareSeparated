#ifndef output_h
#define output_h

/**
    \brief This function scans 3 coefficients of the quadratic equation.

    It uses stucture to combine coefficients into group.
*/
bool GetInput(struct CoefficientsStruct* equation_coefficients);

/**
    \brief This function scans reference values for tests from file.

    It uses structure to combine different values into group.
*/
bool GetFileInput(FILE* fp, struct TestsStruct* test_container);

/**
    \brief This function prints a sentence about number of roots and prints them if exist.
*/
void PrintOutput(const TypeOfRoots number_of_roots, const struct RootsStruct* equation_roots);

#endif

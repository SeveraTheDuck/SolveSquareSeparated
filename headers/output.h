#ifndef output_h
#define output_h

/**
    \brief This function scans 3 coefficients of the quadratic equation
*/
bool GetInput(struct CoefficientsStruct* equation_coefficients);

bool GetFileInput(FILE* fp, struct TestsStruct* test_container);

/**
    \brief This function prints a sentence about number of roots and prints them if exist
*/
void PrintOutput(const TypeOfRoots number_of_roots, const struct RootsStruct equation_roots);

#endif

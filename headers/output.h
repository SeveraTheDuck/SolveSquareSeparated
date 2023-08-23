#ifndef output_h
#define output_h

/**
    \brief This function scans 3 coefficients of the quadratic equation
*/
bool GetInput(double* a, double* b, double* c);

bool GetFileInput(FILE* fp, double* a, double* b, double* c,
                    double* x1_ref, double* x2_ref,
                    int* number_of_roots_ref);

/**
    \brief This function prints a sentence about number of roots and prints them if exist
*/
void PrintOutput(const TypeOfRoots number_of_roots, const double x1, const double x2);

#endif

#ifndef __ARG_H
#define __ARG_H

/**
    \brief This function asks user to input coefficients from console.
*/
void ConsoleInput(struct CoefficientsStruct* equation_coefficients,
                    struct RootsStruct* equation_roots);

/**
    \brief This function gets input coefficients from file.
*/
void FileInput(struct CoefficientsStruct* equation_coefficients,
                    struct RootsStruct* equation_roots,
                    char** argv);

#endif

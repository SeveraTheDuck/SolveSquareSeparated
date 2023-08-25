#ifndef __HEADER_H
#define __HEADER_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define __RED_TEXT__(expression) "\033[31;1m" expression "\033[0m"
#define __GREEN_TEXT__(expression) "\033[32;1m" expression "\033[0m"
#define __YELLOW_TEXT__(expression) "\033[33;1m" expression "\033[0m"

#define MYASSERT(expression)
#ifdef _DEBUG
    #undef MYASSERT
    #define MYASSERT(expression) \
        if (expression == 0) \
        { \
            printf("ERROR in file %s,\nline %d\n", __FILE__, __LINE__); \
            abort(); \
        }
#endif

/**
    \brief This constant is being used for double comparison.
*/
const double EPS = 1.0e-9;

/**
    \brief This enum names cases of different number of roots.

    Solving the equation, you can face 4 different cases. They are stated here.
*/
enum TypeOfRoots
{
    SS_NO_ROOTS = 0,  ///< This is case of no roots
    SS_ONE_ROOT = 1,  ///< This is case of one root
    SS_TWO_ROOTS = 2, ///< This is case of two roots
    SS_INF_ROOTS = 3  ///< This is case of infinite number of roots
};

/**
    \brief This structure is being used to combine equation's coefficients into group.
*/
struct CoefficientsStruct
{
    double a, b, c;
};

/**
    \brief This structure is being used to combine equation's roots into group.
*/
struct RootsStruct
{
    double x1, x2;
};

/**
    \brief This structure is being used to combine reference values for tests.

    a, b, c stand for equation's coefficients,
    x1_ref and x2_ref stand for equation's reference roots,
    number_of_roots_ref stands for equation's reference number of roots.
*/
struct TestsStruct
{
    struct CoefficientsStruct equation_coefficients;
    struct RootsStruct        equation_roots_ref;
    int number_of_roots_ref;
};

#endif

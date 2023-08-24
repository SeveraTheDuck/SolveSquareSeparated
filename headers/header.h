#ifndef header_h
#define header_h

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**
    \brief This enum names cases of different number of roots.

    Solving the equation, you can face 4 different cases. They are stated here.
*/
enum TypeOfRoots
{
    SS_NO_ROOTS = 0,
    SS_ONE_ROOT = 1,
    SS_TWO_ROOTS = 2,
    SS_INF_ROOTS = 3
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
    double a, b, c;
    double x1_ref, x2_ref;
    int number_of_roots_ref = SS_NO_ROOTS;
};

/**
    \brief This constant is being used for double comparison.
*/
const double EPS = 1.0e-9;

#include "simple.h"
#include "solve.h"
#include "output.h"
#include "test.h"

#endif

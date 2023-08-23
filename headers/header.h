#ifndef header_h
#define header_h

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**
    \brief This enum names cases of different number of roots.
*/
enum TypeOfRoots
{
    SS_NO_ROOTS = 0,
    SS_ONE_ROOT = 1,
    SS_TWO_ROOTS = 2,
    SS_INF_ROOTS = 3
};

struct CoefficientsStruct
{
    double a = 0;
    double b = 0;
    double c = 0;
};

struct RootsStruct
{
    double x1 = 0;
    double x2 = 0;
};

struct TestsStruct
{
    double a = 0;
    double b = 0;
    double c = 0;
    double x1_ref = 0;
    double x2_ref = 0;
    int number_of_roots_ref = SS_NO_ROOTS;
};

/**
    \brief This constant is being used for double comparison
*/
const double EPS = 1.0e-9;

#include "simple.h"
#include "solve.h"
#include "output.h"
#include "test.h"

#endif

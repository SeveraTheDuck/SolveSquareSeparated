#ifndef header_h
#define header_h

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**
    \brief This enum names cases of different number of roots
*/
enum TypeOfRoots
{
    SS_NO_ROOTS = 0,
    SS_ONE_ROOT = 1,
    SS_TWO_ROOTS = 2,
    SS_INF_ROOTS = 3
};

/**
    \brief This constant is being used for double comparison
*/
const double EPS = 1.0e-9;

#include "simple.h"
#include "solve.h"
#include "output.h"

#endif

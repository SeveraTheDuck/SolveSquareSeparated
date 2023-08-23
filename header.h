#ifndef header_h
#define header_h

#include <stdio.h>
#include <math.h>
#include <assert.h>

enum TypeOfRoots
{
    SS_NO_ROOTS = 0,
    SS_ONE_ROOT = 1,
    SS_TWO_ROOTS = 2,
    SS_INF_ROOTS = 3
};

const double EPS = 1.0e-9;

#include "simple.h"
#include "solve.h"
#include "output.h"

#endif

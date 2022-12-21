#pragma once
#include <math.h>

#define TOLERANCE 0.0001

static bool isEqual1D(double x, double y ){
    return fabs(x-y) < TOLERANCE;//fabs return the absolute value
}

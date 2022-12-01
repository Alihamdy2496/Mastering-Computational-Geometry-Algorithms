
#include "vector.h"

namespace CGA{
    double_t crossProduct2D(vector2d _vect1, vector2d _vect2){
        return _vect1[X] * _vect2[Y] + _vect1[Y] * _vect2[X] ;
    }


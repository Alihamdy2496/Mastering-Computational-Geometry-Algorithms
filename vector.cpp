
#include "vector.h"

namespace CGA{
    double_t crossProduct2D(vector2d _vect1, vector2d _vect2){
        return _vect1[X] * _vect2[Y] + _vect1[Y] * _vect2[X] ;
    }

    vector3d crossProduct3D(vector3d _vect1, vector3d _vect2){
        vector3d product;
        product.assign( X , _vect1[Y] * _vect2[Z] - _vect1[Z] * _vect2[Y]);
        product.assign( Y , _vect1[Z] * _vect2[X] - _vect1[X] * _vect2[Z]);
        product.assign( Z , _vect1[X] * _vect2[Y] - _vect1[Y] * _vect2[X]);
        return product;
    }
}

#include "vector.h"

namespace CGA{
    double crossProduct2D(vector2d _vect1, vector2d _vect2){
        return _vect1[X] * _vect2[Y] + _vect1[Y] * _vect2[X] ;
    }

    vector3d crossProduct3D(vector3d _vect1, vector3d _vect2){
        vector3d product;
        product.assign( X , _vect1[Y] * _vect2[Z] - _vect1[Z] * _vect2[Y]);
        product.assign( Y , _vect1[Z] * _vect2[X] - _vect1[X] * _vect2[Z]);
        product.assign( Z , _vect1[X] * _vect2[Y] - _vect1[Y] * _vect2[X]);
        return product;
    }

    double scalerTripleProduct(vector3d _vect1,vector3d _vect2,vector3d _vect3){
        /*The scalar triple product of three vectors a, b, and c is (a×b)⋅c.
         *It is a scalar product because, just like the dot product, it evaluates to a single number. 
         (In this way, it is unlike the cross product, which is a vector.) 
         The scalar triple product is important because its absolute value |(a×b)⋅c| is the volume of the parallelepiped 
         spanned by a, b, and c (i.e., the parallelepiped whose adjacent sides are the vectors a, b, and c).*/
        vector3d _vect2Cross_vect3;
        _vect2Cross_vect3 = crossProduct3D(_vect2, _vect3);
        return dotProduct(_vect1, _vect2Cross_vect3);
    }

}
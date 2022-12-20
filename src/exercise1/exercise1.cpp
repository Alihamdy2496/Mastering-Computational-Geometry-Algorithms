#include <iostream>
#include "vector.h"

int main(){
    CGA::vector3d _vect1 (3,5,4);
    CGA::vector3d _vect2 (6,9,1);
    double result = 0.0;
    result = CGA::dotProduct(_vect1 , _vect2);
    std::cout<< "dot product result "<<result<<std::endl;
    CGA::vector3d vector3dResult ;
    vector3dResult = CGA::crossProduct3D(_vect1 , _vect2);
    std::cout<< "cross product result "<<vector3dResult[X]<<" "<<vector3dResult[Y]<<" "<<vector3dResult[Z]<<std::endl;

}
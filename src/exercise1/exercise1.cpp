#include <iostream>
#include "vector.h"

double calculate(CGA::vector3d _vectA, CGA::vector3d _vectB, CGA::vector3d _vectC){
    return CGA::scalerTripleProduct(_vectA , _vectB, _vectC) + CGA::scalerTripleProduct(_vectB , _vectA, _vectC) + CGA::dotProduct(_vectC, _vectC);
}

int main(){
    CGA::vector3d _vect1 (3,5,4);
    CGA::vector3d _vect2 (6,9,1);
    CGA::vector3d _vect3 (9,7,6);
    double result = 0.0;
    result = CGA::dotProduct(_vect1 , _vect2);
    std::cout<< "dot product result "<<result<<std::endl;
    CGA::vector3d vector3dResult ;
    vector3dResult = CGA::crossProduct3D(_vect1 , _vect2);
    std::cout<< "cross product result "<<vector3dResult[X]<<" "<<vector3dResult[Y]<<" "<<vector3dResult[Z]<<std::endl;
    result = CGA::scalerTripleProduct(_vect1 , _vect2, _vect3);
    std::cout<< "scalerTripleProduct result "<<result<<std::endl;
    result = calculate(_vect1 , _vect2, _vect3);
    std::cout<< "calculate result "<<result<<std::endl;
}

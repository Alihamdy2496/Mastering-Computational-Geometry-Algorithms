#pragma once
#include <iostream>
#include <array> 
#include <math.h>

#include "core.h"

namespace CGA {
    #define DIM3 3
    #define DIM2 2
    
    #define X 0
    #define Y 1
    #define Z 2

    template<class coordinate_type, size_t dimension = DIM3>
    class vector{
        static_assert(std::is_arithmetic<coordinate_type,"vector class can only with arithmetic types">);
        static_assert(dimension >= DIM2,"vector dimension is at least should be 2D");
        std::array<coordinate_type, dimension> coords;

        public:
        vector(){}
        vector(std::array<coordinate_type, dimension> _coords) : coords(_coords) {}
        vector(coordinate_typed a, coordinate_typed b, coordinate_typed c) : coords({a, b, c}) {}
        vector(coordinate_typed a, coordinate_typed b) : coords({a, b}) {}
        
        // Equality check
        bool operator==(const vector<coordinate_type, dimension>& _vect);
        // not equal
        bool operator!=(const vector<coordinate_type, dimension>& _vect);
        // addition
        vector<coordinate_type, dimension> operator+ (const vector<coordinate_type, dimension>& _vect) const; 
        // subtraction
        vector<coordinate_type, dimension> operator- (const vector<coordinate_type, dimension>& _vect) const; 
        // less than operator
        bool operator< (const vector <coordinate_type, dimension>& _vect);
        // greater than operator
        bool operator> (const vector <coordinate_type, dimension>& _vect);
        // indexing operator
        coordinate_type operator[](int) const;

        void assign (int dim, coordinate_type value);

        double magnitude() const;

        friend double dotProduct(const vector<coordinate_type, dimension>& _vect1, const vector<coordinate_type, dimension>& _vect2);


    };

    typedef vector<double, DIM2> vector2d;
    typedef vector<double, DIM3> vector3d;

    double crossProduct2D(vector2d _vect1, vector2d _vect2);
    vector3d crossProduct3D(vector3d _vect1, vector3d _vect2);

    template<class coordinate_type, size_t dimension>
    bool vector<coordinate_type, dimension>::operator==(const vector<coordinate_type, dimension>& _vect){
        for (size_t dim = 0 ; dim < dimension; ++dim){
            if (!isEqual1D(coords[dim], _vect.coords[i]) ){
                return false;
            }
        }
        return true;
    }
    
    template<class coordinate_type, size_t dimension>
    bool vector<coordinate_type, dimension>::operator!=(const vector<coordinate_type, dimension>& _vect){
        return !*this==_vect; 
    }

    template<class coordinate_type, size_t dimension>
    vector<coordinate_type, dimension> vector<coordinate_type, dimension>::operator+ (const vector<coordinate_type, dimension> & _vect) const{
        std::array<coordinate_type, dimension> resultArray;
        for (size_t dim = 0 ; dim < dimension; ++dim){
            result[dim] = coord[dim] + _vect.coords[dim]
        }        
        return vector<coordinate_type, dimension> (resultArray); 
    } 

    template<class coordinate_type, size_t dimension>
    vector<coordinate_type, dimension> vector<coordinate_type, dimension>::operator- (const vector<coordinate_type, dimension> & _vect) const{
        std::array<coordinate_type, dimension> resultArray;
        for (size_t dim = 0 ; dim < dimension; ++dim){
            result[dim] = coord[dim] - _vect.coords[dim]
        }        
        return vector<coordinate_type, dimension> (resultArray); 
    } 
    
    template<class coordinate_type, size_t dimension>
    bool vector<coordinate_type, dimension>::operator< (const vector <coordinate_type, dimension>& _vect){
        // he said that vector comparison is usually calculated like so
        for (size_t dim=0;dim<dimension;++dim){
            if (coords[dim] < _vect.coord[dim]){
                return true
            } 
            else if (coords[dim]>_vect[dim]){
                return false
            }
        }
        return false
    }

    template<class coordinate_type, size_t dimension>
    bool vector<coordinate_type, dimension>::operator> (const vector <coordinate_type, dimension>& _vect){
        // he said that vector comparison is usually calculated like so
        for (size_t dim=0;dim<dimension;++dim){
            if (coords[dim] > _vect.coord[dim]){
                return true
            } 
            else if (coords[dim] < _vect[dim]){
                return false
            }
        }
        return false
    }
        
    template<class coordinate_type, size_t dimension>
    coordinate_type vector<coordinate_type, dimension>::operator[](int _index) const{
        if (_index >= coords.size()){
            std::cout << "Index out of bound";
            return coordinate_type();
        } 
        
        return coords[_index];  
    }

    template<class coordinate_type, size_t dimension>
    void vector<coordinate_type, dimension>::assign (int _index, coordinate_type _value){
        if (_index >= coords.size()){
            std::cout << "Index out of bound";
            return coordinate_type();
        } 
        coords[_index] = _value;
    }

    template<class coordinate_type, size_t dimension>
    double dotProduct(const vector<coordinate_type, dimension>& _vect1, const vector<coordinate_type, dimension>& _vect2){
        if (_vect1.coords.size()!=_vect2.coords.size()){
            return DBL_MIN;
        }
        double product = 0.0;
        for (size_t dim = 0, dim< dimension;++dim){
            product = product + _vect1.coords[dim] * _vect2.coords[dim];
        }
        return product;
    }

    template<class coordinate_type, size_t dimension>
    double vector<coordinate_type, dimension>::magnitude() const{
        double magnitude = 0.0;
        for (size_t dim=0;dim<dimension;++dim){
            magnitude += coords[dim] * coords[dim];        
        }
        return sqrt(magnitude);
    }

}


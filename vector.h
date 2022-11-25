#pragma once

#include <iostream>
#include <array> 
#include "core.h"

namespace CGA {
    #define DIM3 3
    #define DIM2 2
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
        bool operator==(const vector<coordinate_type, dimension>& vect);
        // not equal
        bool operator!=(const vector<coordinate_type, dimension>& vect);
        // addition
        vector<coordinate_type, dimension> operator+ (const vector<coordinate_type, dimension>& vect) const; 
        // subtraction
        vector<coordinate_type, dimension> operator- (const vector<coordinate_type, dimension>& vect) const; 
        // less than operator

        // greater than operator
    };
    template<class coordinate_type, size_t dimension>
    bool vector<coordinate_type, dimension>::operator==(const vector<coordinate_type, dimension>& vect){
        for (size_t dim = 0 ; dim < dimension; ++dim){
            if (!isEqual1D(coords[dim], vect.coords[i]) ){
                return false;
            }
        }
        return true;
    }
    
    template<class coordinate_type, size_t dimension>
    bool vector<coordinate_type, dimension>::operator!=(const vector<coordinate_type, dimension>& vect){
        return !*this==vect; 
    }

    template<class coordinate_type, size_t dimension>
    vector<coordinate_type, dimension> vector<coordinate_type, dimension>::operator+ (const vector<coordinate_type, dimension> & vect) const{
        std::array<coordinate_type, dimension> resultArray;
        for (size_t dim = 0 ; dim < dimension; ++dim){
            result[dim] = coord[dim] + vect.coords[dim]
        }        
        return vector<coordinate_type, dimension> (resultArray); 
    } 

    template<class coordinate_type, size_t dimension>
    vector<coordinate_type, dimension> vector<coordinate_type, dimension>::operator- (const vector<coordinate_type, dimension> & vect) const{
        std::array<coordinate_type, dimension> resultArray;
        for (size_t dim = 0 ; dim < dimension; ++dim){
            result[dim] = coord[dim] - vect.coords[dim]
        }        
        return vector<coordinate_type, dimension> (resultArray); 
    } 

}


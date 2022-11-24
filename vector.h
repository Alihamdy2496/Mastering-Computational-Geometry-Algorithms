#pragma once

#include <iostream>
#include <array> 


namespace CGA {
    #define DIM3 3
    #define DIM2 2
    template<class coordinate_type, size_t dimension = DIM3>
    class vector{
        static_assert(std::is_arithmetic<coordinate_type,"vector class can only with arithmetic types">);
        static_assert(dimension >= DIM2,"vector dimension is at least should be 2D");

        std::array<coordinate_type, dimension> coords;
    };
}
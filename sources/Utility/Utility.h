#pragma once

#include <cmath>

template<typename Tval>
struct MyHash {
    std::size_t operator()(const Tval* val) const {
        static const size_t shift = (size_t)log2(1 + sizeof(Tval));
        return (size_t)(val) >> shift;
    }
};

enum Direction { NORTH, SOUTH, EAST, WEST };

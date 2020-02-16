#pragma once

#include <cmath>

template<typename Tval>
struct MyHash {
    std::size_t operator()(const Tval* val) const {
        static const size_t shift = (size_t)log2(1 + sizeof(Tval));
        return (size_t)(val) >> shift;
    }
};

enum class Direction { NORTH, SOUTH, EAST, WEST };

enum class EquipmentType {WEAPON, ARMOR};
enum class ArmorType {NONE, HEAD, BODY, LEGS, BOOTS};

struct Penetration {
    float sharp, blunt, heat;
};

enum class StatType {
    HEALTH, ACCURACY, EVASION, ARMOR, HUNGER, STRENGTH, EXPERIENCE, LEVEL
};

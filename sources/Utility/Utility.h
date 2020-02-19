#pragma once

#include <cmath>

enum class RoomType { STANDARD };

enum class MazeType { STANDARD };

template<typename Tval>
struct MyHash {
    std::size_t operator()(const Tval* val) const {
        static const size_t shift = (size_t)log2(1 + sizeof(Tval));
        return (size_t)(val) >> shift;
    }
};

enum class Direction { NORTH, SOUTH, EAST, WEST };

enum ItemType { ITEM, EQUIPMENT };
enum class EquipmentType {WEAPON, ARMOR};

enum class ArmorType {NONE, HEAD, BODY, LEGS, BOOTS};
enum class WeaponType {FIRST};

struct Penetration {
    float sharp, blunt, heat;
};

enum class StatType {
    HEALTH, HUNGER, MAX_HEALTH, MAX_HUNGER, ACCURACY, EVASION, STRENGTH, EXPERIENCE, LEVEL, ARMOR
};

#include "AbstractRoom.h"

const std::unordered_map<Direction, std::vector<Door*>>& AbstractRoom::getDoors() const {
    return this->doors;
}

void AbstractRoom::addDoor(Door* door) noexcept {
    this->doors[door->getDirection()].push_back(door);
}

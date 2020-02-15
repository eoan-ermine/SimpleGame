#include "AbstractRoom.h"

const std::unordered_map<Direction, std::vector<std::pair<Door*, AbstractRoom*>>>& AbstractRoom::getDoors() const {
    return this->doors;
}

void AbstractRoom::addDoor(Door* door, AbstractRoom* destination) noexcept {
    this->doors[door->getDirection()].push_back({door, destination});
}

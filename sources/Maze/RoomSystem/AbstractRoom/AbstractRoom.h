#pragma once

#include "../../DoorSystem/Door.h"

#include <unordered_map>
#include <vector>

class AbstractRoom {
private:
    std::unordered_map<Direction, std::vector<std::pair<Door*, AbstractRoom*>>> doors;
public:
    const std::unordered_map<Direction, std::vector<std::pair<Door*, AbstractRoom*>>>& getDoors() const;
    void addDoor(Door* door, AbstractRoom* destination) noexcept;
};

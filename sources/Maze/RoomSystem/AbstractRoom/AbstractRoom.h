#pragma once

#include "../../DoorSystem/Door.h"

#include <unordered_map>
#include <vector>

class AbstractRoom {
private:
    std::unordered_map<Direction, std::vector<Door*>> doors;
public:
    const std::unordered_map<Direction, std::vector<Door*>>& getDoors() const;
    void addDoor(Door* door) noexcept;
};

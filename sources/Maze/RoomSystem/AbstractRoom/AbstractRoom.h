#pragma once

#include <stdexcept>

#include "../../DoorSystem/Door.h"
#include "../../../Utility/Utility.h"
#include "../../../Item/Inventory/Inventory.h"

#include <unordered_map>

class AbstractRoom {
private:
    MyHash<Door> hash;
    std::unordered_map<std::size_t, Door*> doors;
    Inventory inventory;
public:
    const std::unordered_map<std::size_t, Door*>& getDoors() const;

    void addDoor(Door* door) noexcept;
    void deleteDoor(Door* door) noexcept;
    void deleteDoors() noexcept;

    bool contains(Door* door) const noexcept;
    bool contains(size_t hash) const noexcept;

    Door* getDoor(size_t hash) const;
    Door* operator[](size_t hash) const noexcept;

    Inventory* getInventory();
};

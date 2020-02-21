#pragma once

#include <stdexcept>

#include "../../DoorSystem/AbstractDoor/AbstractDoor.h"
#include "../../../Item/Inventory/Inventory.h"
#include "../../../GameWindow/Game/GameObject/GameObject.h"

#include <algorithm>
#include <vector>

class AbstractRoom: public GameObject {
private:
    std::vector<AbstractDoor*> doors;
    Inventory inventory;
public:
    const std::vector<AbstractDoor*>& getDoors() const;

    void addDoor(AbstractDoor* door) noexcept;
    void deleteDoor(AbstractDoor* door) noexcept;
    void deleteDoors() noexcept;

    bool contains(AbstractDoor* door) const noexcept;
    Inventory* getInventory();
};

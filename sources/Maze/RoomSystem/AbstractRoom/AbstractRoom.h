#pragma once

#include <stdexcept>

#include "../../DoorSystem/AbstractDoor/AbstractDoor.h"
#include "../../../Item/Inventory/Inventory.h"
#include "../../../GameWindow/Game/GameObject/GameObject.h"

#include <algorithm>
#include <vector>

class AbstractPlayer;

class AbstractRoom: public GameObject {
private:
    std::vector<AbstractPlayer*> players;
    std::vector<AbstractDoor*> doors;
    Inventory inventory;
public:
    const std::vector<AbstractPlayer*>& getPlayers() const;
    const std::vector<AbstractDoor*>& getDoors() const;

    void addDoor(AbstractDoor* door) noexcept;
    void deleteDoor(AbstractDoor* door) noexcept;
    void deleteDoors() noexcept;

    void addPlayer(AbstractPlayer* player) noexcept;
    void deletePlayer(AbstractPlayer* player) noexcept;
    void deletePlayers() noexcept;

    bool contains(AbstractDoor* door) const noexcept;
    bool contains(AbstractPlayer* player) const noexcept;

    Inventory* getInventory();
};

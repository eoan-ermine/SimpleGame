#include "AbstractRoom.h"

const std::vector<AbstractDoor*>& AbstractRoom::getDoors() const {
    return this->doors;
}

void AbstractRoom::addDoor(AbstractDoor* door) noexcept {
    doors.push_back(door);
}

void AbstractRoom::deleteDoor(AbstractDoor* door) noexcept {
    if(auto it = std::find(doors.begin(), doors.end(), door); it != doors.end()) {
        doors.erase(it);
    }
}

void AbstractRoom::deleteDoors() noexcept {
    doors.clear();
}

bool AbstractRoom::contains(AbstractDoor* door) const noexcept {
    return std::find(doors.begin(), doors.end(), door) != doors.end();
}

Inventory* AbstractRoom::getInventory() {
    return &inventory;
}

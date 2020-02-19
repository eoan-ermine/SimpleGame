#include "AbstractRoom.h"

const std::unordered_map<std::size_t, Door*>& AbstractRoom::getDoors() const {
    return this->doors;
}

void AbstractRoom::addDoor(Door* door) noexcept {
    doors.insert({hash(door), door});
}

void AbstractRoom::deleteDoor(Door* door) noexcept {
    doors.erase(hash(door));
}

void AbstractRoom::deleteDoors() noexcept {
    doors.clear();
}

bool AbstractRoom::contains(Door* door) const noexcept {
    return doors.find(hash(door)) != doors.end();
}

bool AbstractRoom::contains(size_t hash) const noexcept {
    return doors.find(hash) != doors.end();
}

Door* AbstractRoom::getDoor(size_t hash) const {
    if(auto it = doors.find(hash); it != doors.end()) {
        return (*it).second;
    } else {
        throw std::out_of_range("Can't found door with provided hash");
    }
}

Door* AbstractRoom::operator[](size_t hash) const noexcept {
    if(auto it = doors.find(hash); it != doors.end()) {
        return (*it).second;
    } else {
        return nullptr;
    }
}

Inventory* AbstractRoom::getInventory() {
    return &inventory;
}

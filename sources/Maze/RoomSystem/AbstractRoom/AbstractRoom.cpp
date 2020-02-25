#include "AbstractRoom.h"

#include "../../../Player/AbstractPlayer/AbstractPlayer.h"

const std::vector<AbstractPlayer*>& AbstractRoom::getPlayers() const {
    return this->players;
}

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

void AbstractRoom::addPlayer(AbstractPlayer* player) noexcept {
    this->players.push_back(player);
}

void AbstractRoom::deletePlayer(AbstractPlayer* player) noexcept {
    if(auto it = std::find(players.begin(), players.end(), player); it != players.end()) {
        players.erase(it);
    }
}

void AbstractRoom::deletePlayers() noexcept {
    players.clear();
}

bool AbstractRoom::contains(AbstractPlayer* player) const noexcept {
    return std::find(players.begin(), players.end(), player) != players.end();
}

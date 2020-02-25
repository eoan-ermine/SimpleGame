#include "AbstractMaze.h"

AbstractMaze::AbstractMaze() {
}

AbstractMaze::~AbstractMaze() {
}

void AbstractMaze::addRoom(AbstractRoom* room) noexcept {
    rooms.push_back(room);
}

void AbstractMaze::deleteRoom(AbstractRoom* room) noexcept {
    if(auto it = std::find(rooms.begin(), rooms.end(), room); it != rooms.end()) {
        rooms.erase(it);
    }
}

void AbstractMaze::reset() noexcept {
    rooms.clear();
}

const std::vector<AbstractRoom*>& AbstractMaze::getRooms() {
    return rooms;
}

std::size_t AbstractMaze::countOfRooms() {
    return rooms.size();
}

void AbstractMaze::addPlayer(AbstractPlayer* player) noexcept {
    this->players.push_back(player);
}

void AbstractMaze::deletePlayer(AbstractPlayer* player) noexcept {
    if(auto it = std::find(players.begin(), players.end(), player); it != players.end()) {
        players.erase(it);
    }
}

void AbstractMaze::deletePlayers() noexcept {
    players.clear();
}

bool AbstractMaze::contains(AbstractPlayer* player) const noexcept {
    return std::find(players.begin(), players.end(), player) != players.end();
}

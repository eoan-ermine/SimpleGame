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

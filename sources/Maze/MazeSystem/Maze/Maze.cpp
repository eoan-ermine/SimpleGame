#include "Maze.h"

Maze::Maze() {
}

Maze::~Maze() {
}

void Maze::addRoom(AbstractRoom* room) noexcept {
    rooms.insert({hash(room), room});
}

void Maze::deleteRoom(AbstractRoom* room) noexcept {
    rooms.erase(hash(room));
}

void Maze::reset() noexcept {
    rooms.clear();
}

const std::unordered_map<std::size_t, AbstractRoom*>& Maze::getRooms() {
    return rooms;
}

std::size_t Maze::countOfRooms() {
    return rooms.size();
}

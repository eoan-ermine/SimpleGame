#pragma once

#include "../../RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../../Utility/Utility.h"

#include <vector>

class Maze {
private:
    MyHash<AbstractRoom> hash;
    std::unordered_map<std::size_t, AbstractRoom*> rooms;
public:
    Maze();
    ~Maze();

    void addRoom(AbstractRoom* room) noexcept;
    void deleteRoom(AbstractRoom* room) noexcept;
    void reset() noexcept;

    const std::unordered_map<std::size_t, AbstractRoom*>& getRooms();
    std::size_t countOfRooms();
};

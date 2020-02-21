#pragma once

#include "../../RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../../GameWindow/Game/GameObject/GameObject.h"

#include <algorithm>
#include <vector>

class AbstractMaze: public GameObject {
private:
    std::vector<AbstractRoom*> rooms;
public:
    AbstractMaze();
    ~AbstractMaze();

    void addRoom(AbstractRoom* room) noexcept;
    void deleteRoom(AbstractRoom* room) noexcept;
    void reset() noexcept;

    const std::vector<AbstractRoom*>& getRooms();
    std::size_t countOfRooms();
};

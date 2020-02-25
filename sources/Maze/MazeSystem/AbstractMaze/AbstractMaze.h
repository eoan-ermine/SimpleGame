#pragma once

#include "../../RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../../GameWindow/Game/GameObject/GameObject.h"

#include <algorithm>
#include <vector>

class AbstractMaze: public GameObject {
private:
    std::vector<AbstractPlayer*> players;
    std::vector<AbstractRoom*> rooms;
public:
    AbstractMaze();
    ~AbstractMaze();

    void addRoom(AbstractRoom* room) noexcept;
    void deleteRoom(AbstractRoom* room) noexcept;
    void reset() noexcept;

    void addPlayer(AbstractPlayer* player) noexcept;
    void deletePlayer(AbstractPlayer* player) noexcept;
    void deletePlayers() noexcept;

    bool contains(AbstractPlayer* player) const noexcept;

    const std::vector<AbstractRoom*>& getRooms();
    std::size_t countOfRooms();
};

#pragma once

#include <vector>

#include "../../Maze/MazeSystem/Maze/Maze.h"
#include "../../Maze/RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../Item/Inventory/Inventory.h"
#include "../../Effect/AbstractEffect.h"
#include "../../Effect/StarveEffect/StarveEffect.h"

class AbstractPlayer {
private:
    Maze* currentMaze = nullptr;
    AbstractRoom* currentRoom = nullptr;

    float health, hunger;

    std::vector<AbstractEffect*> effects;
    Inventory inventory;
public:
    AbstractPlayer();
    AbstractPlayer(int health, int hunger);
    ~AbstractPlayer();

    void setMaze(Maze* newMaze) noexcept;
    void setRoom(AbstractRoom* newRoom) noexcept;
    void tick() noexcept;

    void setHealth(int newHealth);
    void changeHealth(int healthDelta);

    void setHunger(int newHunger);
    void changeHunger(int hungerDelta);

    Inventory* getInventory() noexcept;
};

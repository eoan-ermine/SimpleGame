#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>

#include <unordered_map>
#include <vector>

#include "GameObject/GameObject.h"
#include "../../Maze/MazeSystem/AbstractMaze/AbstractMaze.h"
#include "../../Maze/RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../Player/AbstractPlayer/AbstractPlayer.h"
#include "../../Utility/Utility.h"

class Game {
private:
    AbstractMaze* spawnMaze;
    AbstractRoom* spawnRoom;
    AbstractPlayer* player;

    std::unordered_map<ObjectType, std::vector<GameObject*>> gameObjects;
public:
    Game();
    ~Game();

    void addObject(ObjectType type, GameObject* object) noexcept;
    void deleteObject(ObjectType type, GameObject* object) noexcept;
    void update();

    void changeSpawnMaze(AbstractMaze* newMaze) noexcept;
    void changeSpawnRoom(AbstractRoom* room) noexcept;
    void changePlayer(AbstractPlayer* player) noexcept;

    AbstractMaze* getSpawnMaze() const noexcept;
    AbstractRoom* getSpawnRoom() const noexcept;
    AbstractPlayer* getPlayer() const noexcept;

    void updateEffects();
    void writeHunger();
};

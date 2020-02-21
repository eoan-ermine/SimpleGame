#pragma once

#include <algorithm>

#include <iostream>
#include <unordered_map>
#include <vector>

#include "GameObject/GameObject.h"
#include "../../Maze/MazeSystem/Maze/Maze.h"
#include "../../Maze/RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../Player/AbstractPlayer/AbstractPlayer.h"
#include "../../Utility/Utility.h"

class Game {
private:
    Maze* spawnMaze;
    AbstractRoom* spawnRoom;
    AbstractPlayer* player;

    std::unordered_map<ObjectType, std::vector<GameObject*>> gameObjects;
public:
    Game();
    ~Game();

    void addObject(ObjectType type, GameObject* object) noexcept;
    void deleteObject(ObjectType type, GameObject* object) noexcept;
    void update();

    void changeSpawnMaze(Maze* newMaze) noexcept;
    void changeSpawnRoom(AbstractRoom* room) noexcept;
    void changePlayer(AbstractPlayer* player) noexcept;

    Maze* getSpawnMaze() const noexcept;
    AbstractRoom* getSpawnRoom() const noexcept;
    AbstractPlayer* getPlayer() const noexcept;

    void updateEffects();
    void writeHunger();
};

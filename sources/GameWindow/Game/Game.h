#pragma once

#include <algorithm>
#include <vector>

#include "../../Maze/MazeSystem/Maze/Maze.h"
#include "../../Maze/RoomSystem/AbstractRoom/AbstractRoom.h"
#include "../../Player/AbstractPlayer/AbstractPlayer.h"
#include "../../Utility/Utility.h"

class Game {
private:
    Maze* spawnMaze;
    AbstractRoom* spawnRoom;
    AbstractPlayer* player;

    std::vector<Maze*> gameMazes;
    std::vector<AbstractRoom*> gameRooms;
    std::vector<Item*> gameItems;
    std::vector<AbstractPlayer*> gamePlayers;
public:
    Game();
    ~Game();

    void deleteMaze(Maze* toDelete);
    void deleteRoom(AbstractRoom* toDelete);
    void deleteItem(Item* toDelete);
    void deletePlayer(AbstractPlayer* toDelete);
};

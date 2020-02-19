#include "Game.h"

Game::Game(): spawnMaze(new Maze()), spawnRoom(new AbstractRoom()), player(new AbstractPlayer())  {
    spawnMaze->addRoom(spawnRoom);
    player->setRoom(spawnRoom);

    gameMazes.push_back(spawnMaze);
    gameRooms.push_back(spawnRoom);
    gamePlayers.push_back(player);
}

Game::~Game() {
    for(auto& x: gameMazes) {
        delete x;
    }
    for(auto& x: gameRooms) {
        delete x;
    }
    for(auto& x: gamePlayers) {
        delete x;
    }
    for(auto& x: gameItems) {
        delete x;
    }

}

void Game::deleteMaze(Maze* toDelete) {
    if(auto it = std::find(gameMazes.begin(), gameMazes.end(), toDelete); it != gameMazes.end()) {
        gameMazes.erase(it);
    }
}

void Game::deleteRoom(AbstractRoom* toDelete) {
    if(auto it = std::find(gameRooms.begin(), gameRooms.end(), toDelete); it != gameRooms.end()) {
        gameRooms.erase(it);
    }
}

void Game::deleteItem(Item* toDelete) {
    if(auto it = std::find(gameItems.begin(), gameItems.end(), toDelete); it != gameItems.end()) {
        gameItems.erase(it);
    }
}

#include "Game.h"

Game::Game(): spawnMaze(new AbstractMaze()), spawnRoom(new AbstractRoom()), player(new AbstractPlayer()) {
    spawnMaze->addRoom(spawnRoom);
    player->setRoom(spawnRoom);

    gameObjects[ObjectType::MAZE].push_back(spawnMaze);
    gameObjects[ObjectType::ROOM].push_back(spawnRoom);
    gameObjects[ObjectType::PLAYER].push_back(player);
}

Game::~Game() {
    for(auto& pair: gameObjects) {
        for(auto& element: pair.second) {
            delete element;
        }
    }
}

void Game::addObject(ObjectType type, GameObject* object) noexcept {
    gameObjects[type].push_back(object);
}

void Game::deleteObject(ObjectType type, GameObject* toDelete) noexcept {
    std::vector<GameObject*>& categoryRef = gameObjects[type];
    if(auto it = std::find(categoryRef.begin(), categoryRef.end(), toDelete); it != categoryRef.end()) {
        categoryRef.erase(it);
    }
}

void Game::update() {
    this->updateEffects();
    this->writeHunger();
}

void Game::updateEffects() {
    std::vector<std::pair<ObjectType, GameObject*>> toDelete;
    for(GameObject* object: gameObjects[ObjectType::PLAYER]) {
        AbstractPlayer* player = dynamic_cast<AbstractPlayer*>(object);
        if(player == nullptr) {
            throw std::runtime_error("Excepted AbstractPlayer got other class");
        }
        for(AbstractEffect* effect: player->getEffects()) {
            if(effect->getRemains() > 0) {
                effect->action(player);
            } else {
                toDelete.push_back({ObjectType::EFFECT, dynamic_cast<GameObject*>(effect)});
            }
        }
    }
    for(auto pair: toDelete) {
        this->deleteObject(pair.first, pair.second);
    }
}

void Game::writeHunger() {
    std::cout << this->player->getStat(StatType::HUNGER) << std::endl;
}


void Game::changeSpawnMaze(AbstractMaze* newMaze) noexcept {
    std::vector<GameObject*>& category = gameObjects[ObjectType::MAZE];
    if(auto it = std::find(category.begin(), category.end(), newMaze); it == category.end()) {
        category.push_back(newMaze);
    }
    spawnMaze = newMaze;
}

void Game::changeSpawnRoom(AbstractRoom* newRoom) noexcept {
    std::vector<GameObject*>& category = gameObjects[ObjectType::ROOM];
    if(auto it = std::find(category.begin(), category.end(), newRoom); it == category.end()) {
        category.push_back(newRoom);
    }
    spawnRoom = newRoom;
}

void Game::changePlayer(AbstractPlayer* newPlayer) noexcept {
    std::vector<GameObject*>& category = gameObjects[ObjectType::PLAYER];
    if(auto it = std::find(category.begin(), category.end(), newPlayer); it == category.end()) {
        category.push_back(newPlayer);
    }
    player = newPlayer;
}

AbstractMaze* Game::getSpawnMaze() const noexcept {
    return spawnMaze;
}

AbstractRoom* Game::getSpawnRoom() const noexcept {
    return spawnRoom;
}

AbstractPlayer* Game::getPlayer() const noexcept {
    return player;
}

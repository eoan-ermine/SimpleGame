#include "AbstractPlayer.h"

AbstractPlayer::AbstractPlayer(): health(100), hunger(100) {
    effects.push_back(new StarveEffect(0));
}


AbstractPlayer::AbstractPlayer(int health, int hunger): health(health), hunger(hunger) {
}

AbstractPlayer::~AbstractPlayer() {
}


void AbstractPlayer::setMaze(Maze* newMaze) noexcept {
    this->currentMaze = newMaze;
}

void AbstractPlayer::setRoom(AbstractRoom* newRoom) noexcept {
    this->currentRoom = newRoom;
}

Inventory* AbstractPlayer::getInventory() noexcept {
    return &(this->inventory);
}

void AbstractPlayer::tick() noexcept {
    for(AbstractEffect* effect: effects) {
        effect->action(this);
    }
}

void AbstractPlayer::setHealth(int newHealth) {
    this->health = newHealth;
}

void AbstractPlayer::changeHealth(int healthDelta) {
    this->health += healthDelta;
}

void AbstractPlayer::setHunger(int newHunger) {
    this->hunger = newHunger;
}

void AbstractPlayer::changeHunger(int hungerDelta) {
    this->hunger += hungerDelta;
}

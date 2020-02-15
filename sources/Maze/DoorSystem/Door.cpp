#include "Door.h"

Door::Door(Direction direction): direction(direction) {
}

Door::~Door() {
}

Direction Door::getDirection() const noexcept {
    return this->direction;
}

void Door::setDirection(Direction newDirection) noexcept {
    this->direction = newDirection;
}

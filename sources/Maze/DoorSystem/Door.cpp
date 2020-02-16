#include "Door.h"

#include "../../Player/AbstractPlayer/AbstractPlayer.h"

Door::Door(AbstractRoom* source, AbstractRoom* destination, Direction direction): source(source), destination(destination), direction(direction) {
}

Door::~Door() {
}

Direction Door::getDirection() const noexcept {
    return this->direction;
}

void Door::setDirection(Direction newDirection) noexcept {
    this->direction = newDirection;
}

void Door::setDestination(AbstractRoom* newDestination) noexcept {
    this->destination = newDestination;
}

void Door::setSource(AbstractRoom* newSource) noexcept {
    this->source = newSource;
}

void Door::use(AbstractPlayer* ply) {
    if(ply->getRoom() == this->source) {
        ply->setRoom(this->destination);
    }
}

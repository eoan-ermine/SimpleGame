#include "AbstractDoor.h"

#include "../../../Player/AbstractPlayer/AbstractPlayer.h"

AbstractDoor::AbstractDoor(AbstractRoom* source, AbstractRoom* destination, Direction direction): source(source), destination(destination), direction(direction) {
}

AbstractDoor::~AbstractDoor() {
}

Direction AbstractDoor::getDirection() const noexcept {
    return this->direction;
}

void AbstractDoor::setDirection(Direction newDirection) noexcept {
    this->direction = newDirection;
}

void AbstractDoor::setDestination(AbstractRoom* newDestination) noexcept {
    this->destination = newDestination;
}

void AbstractDoor::setSource(AbstractRoom* newSource) noexcept {
    this->source = newSource;
}

void AbstractDoor::use(AbstractPlayer* ply) {
    if(ply->getRoom() == this->source) {
        ply->setRoom(this->destination);
    }
}

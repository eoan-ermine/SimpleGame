#pragma once

#include "../../Utility/Utility.h"

class AbstractRoom;
class AbstractPlayer;

class Door {
private:
    AbstractRoom *source, *destination;
    Direction direction;
public:
    Door(AbstractRoom* source, AbstractRoom* destination, Direction direction);
    ~Door();

    Direction getDirection() const noexcept;

    void use(AbstractPlayer* ply);

    void setSource(AbstractRoom* newSource) noexcept;
    void setDestination(AbstractRoom* newDestination) noexcept;
    void setDirection(Direction newDirection) noexcept;
};

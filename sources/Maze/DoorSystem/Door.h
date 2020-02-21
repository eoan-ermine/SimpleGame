#pragma once

#include "../../Utility/Utility.h"
#include "../../GameWindow/Game/GameObject/GameObject.h"

class AbstractRoom;
class AbstractPlayer;

class Door: public GameObject {
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

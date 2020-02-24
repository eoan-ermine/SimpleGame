#pragma once

#include "../../../Utility/Utility.h"
#include "../../../GameWindow/Game/GameObject/GameObject.h"

class AbstractRoom;
class AbstractPlayer;

class AbstractDoor: public GameObject {
private:
    AbstractRoom *source, *destination;
    Direction direction;
public:
    AbstractDoor(AbstractRoom* source, AbstractRoom* destination, Direction direction);
    ~AbstractDoor();

    Direction getDirection() const noexcept;
	AbstractRoom* getDestination() noexcept;
	AbstractRoom* getSource() noexcept;

    void use(AbstractPlayer* ply);

    void setSource(AbstractRoom* newSource) noexcept;
    void setDestination(AbstractRoom* newDestination) noexcept;
    void setDirection(Direction newDirection) noexcept;
};

#pragma once

#include "../../Utility/Utility.h"

class Door {
private:
    Direction direction;
public:
    Door(Direction direction);
    ~Door();

    Direction getDirection() const noexcept;
    void setDirection(Direction newDirection) noexcept;
};

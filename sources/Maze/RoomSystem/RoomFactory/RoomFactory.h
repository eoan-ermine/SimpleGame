#pragma once

#include "../StandardRoom/StandardRoom.h"

enum RoomType { STANDARD };

class RoomFactory
{
public:
    RoomFactory();
    ~RoomFactory();

    AbstractRoom* createRoom(RoomType type);
};


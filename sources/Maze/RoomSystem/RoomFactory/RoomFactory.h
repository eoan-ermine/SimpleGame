#pragma once

#include "../StandardRoom/StandardRoom.h"
#include "../../../Utility/Utility.h"

class RoomFactory {
public:
    RoomFactory();
    ~RoomFactory();

    static AbstractRoom* createRoom(RoomType type);
};

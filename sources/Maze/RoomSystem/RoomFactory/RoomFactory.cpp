#include "RoomFactory.h"

RoomFactory::RoomFactory() {
}

RoomFactory::~RoomFactory() {
}

AbstractRoom* RoomFactory::createRoom(RoomType type) {
    switch(type) {
    case RoomType::STANDARD:
        return new StandardRoom();
    default:
        return new StandardRoom();
    }
}

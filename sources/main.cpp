#include <iostream>

#include "Player/AbstractPlayer/AbstractPlayer.h"
#include "Maze/MazeSystem/Maze/Maze.h"
#include "Maze/RoomSystem/AbstractRoom/AbstractRoom.h"

int main() {
    AbstractPlayer player;

    Maze maze;

    AbstractRoom* room = new AbstractRoom();
    Door* door = new Door(Direction::EAST);
    room->addDoor(door, nullptr);

    maze.addRoom(room);
}

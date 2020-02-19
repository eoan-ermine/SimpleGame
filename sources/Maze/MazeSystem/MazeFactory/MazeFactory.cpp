#include "MazeFactory.h"

MazeFactory::MazeFactory() {
}

MazeFactory::~MazeFactory() {
}

Maze* MazeFactory::createMaze(MazeType type) {
    switch(type) {
    case MazeType::STANDARD:
        return new Maze();
    default:
        return new Maze();
    }
}

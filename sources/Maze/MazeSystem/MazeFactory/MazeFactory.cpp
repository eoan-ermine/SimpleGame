#include "MazeFactory.h"

MazeFactory::MazeFactory() {
}

MazeFactory::~MazeFactory() {
}

Maze* createMaze(MazeType type) {
    switch(type) {
    case MazeType::STANDARD:
        return new Maze();
    }
}

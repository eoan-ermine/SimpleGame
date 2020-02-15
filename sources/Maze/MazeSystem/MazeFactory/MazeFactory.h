#pragma once

#include "../Maze/Maze.h"

enum MazeType { STANDARD };

class MazeFactory {
public:
    MazeFactory();
    ~MazeFactory();

    Maze* createMaze(MazeType type);
};

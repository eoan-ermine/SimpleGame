#pragma once

#include "../Maze/Maze.h"
#include "../../../Utility/Utility.h"

class MazeFactory {
public:
    MazeFactory();
    ~MazeFactory();

    static Maze* createMaze(MazeType type);
};

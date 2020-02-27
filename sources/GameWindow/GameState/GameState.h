#pragma once

#include <string>
#include <iostream>

class GameState {
protected:
    std::string getInput(std::string prompt=">> ");
    void displayText(std::string text);
public:
    GameState();
    virtual ~GameState();

    virtual GameState* execute() = 0;
};

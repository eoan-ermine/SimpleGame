#pragma once

#include <SFML/Graphics.hpp>
#include <utility>
#include <string>
#include <iostream>

#include "../AbstractGameWindow/AbstractGameWindow.h"

enum GameState { INITIALIZATION, MAIN };

class TextGameWindow: public AbstractGameWindow {
public:
    bool windowIsOpen;
    GameState currentState;

    TextGameWindow();
    ~TextGameWindow();
public:
    void show() override;

    void waitInput();
    std::string getInterface();
    void drawInterface(std::string interface);
};

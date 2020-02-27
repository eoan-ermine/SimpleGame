#pragma once

#include <SFML/Graphics.hpp>
#include <utility>
#include <string>
#include <iostream>

#include "../AbstractGameWindow/AbstractGameWindow.h"

#include "../GameState/MenuState/MenuState.h"

class TextGameWindow: public AbstractGameWindow {
public:
    bool windowIsOpen;
    GameState* currentState;

    TextGameWindow();
    ~TextGameWindow();
public:
    void show() override;
    void changeState(GameState* newState);
};

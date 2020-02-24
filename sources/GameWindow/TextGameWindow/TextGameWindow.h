#pragma once

#include <SFML/Graphics.hpp>

#include "../AbstractGameWindow/AbstractGameWindow.h"

class TextGameWindow: public AbstractGameWindow {
public:
    bool windowIsOpen;

    TextGameWindow();
    ~TextGameWindow();
public:
    void show() override;
};

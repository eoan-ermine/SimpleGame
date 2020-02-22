#pragma once

#include "../AbstractGameWindow/AbstractGameWindow.h"

class TextGameWindow: public AbstractGameWindow {
public:
    TextGameWindow();
    ~TextGameWindow();
public:
    void show() override;
};

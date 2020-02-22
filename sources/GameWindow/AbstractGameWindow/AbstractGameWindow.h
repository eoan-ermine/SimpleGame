#pragma once

#include "../Game/Game.h"

class AbstractGameWindow {
protected:
    Game game;
public:
    AbstractGameWindow();
    virtual ~AbstractGameWindow();

    virtual void loadResources();

    void everyTick();
    virtual void show() = 0;

    Game* getGame();
};

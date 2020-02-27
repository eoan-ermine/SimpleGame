#pragma once

#include <cstdlib>
#include "../GameState.h"

class MenuState: public GameState {
public:
    MenuState();
    ~MenuState();

    GameState* execute() override;
};

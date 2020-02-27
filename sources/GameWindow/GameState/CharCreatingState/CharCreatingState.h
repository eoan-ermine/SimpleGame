#pragma once

#include "../GameState.h"

class CharCreatingState: public GameState {
public:
    CharCreatingState();
    ~CharCreatingState();

    GameState* execute() override;
};

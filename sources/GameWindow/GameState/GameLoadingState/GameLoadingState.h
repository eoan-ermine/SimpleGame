#pragma once

#include "../GameState.h"

class GameLoadingState: public GameState {
public:
    GameLoadingState();
    ~GameLoadingState();

    GameState* execute() override;
};

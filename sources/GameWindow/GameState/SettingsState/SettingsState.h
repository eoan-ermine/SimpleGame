#pragma once

#include "../GameState.h"

class SettingsState: public GameState {
public:
    SettingsState();
    ~SettingsState();

    GameState* execute() override;
};

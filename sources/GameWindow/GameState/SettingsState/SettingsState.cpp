#include "SettingsState.h"

SettingsState::SettingsState() {
}

SettingsState::~SettingsState() {
}

GameState* SettingsState::execute() {
    this->displayText("Hi! It's a stub\n");
    this->getInput();

    return nullptr;
}

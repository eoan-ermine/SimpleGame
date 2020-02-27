#include "CharCreatingState.h"

CharCreatingState::CharCreatingState() {
}

CharCreatingState::~CharCreatingState() {
}

GameState* CharCreatingState::execute() {
    this->displayText("Hi! It's a stub\n");
    this->getInput();

    return nullptr;
}

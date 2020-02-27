#include "GameLoadingState.h"

GameLoadingState::GameLoadingState() {
}

GameLoadingState::~GameLoadingState() {
}

GameState* GameLoadingState::execute() {
    this->displayText("Hi! It's a stub\n");
    this->getInput();

    return nullptr;
}

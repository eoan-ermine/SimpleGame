#include "GameState.h"

GameState::GameState() { }

GameState::~GameState() { }

std::string GameState::getInput(std::string prompt) {
    std::string result;
    std::cout << prompt;
    std::getline(std::cin, result);
    return result;
}

void GameState::displayText(std::string text) {
    std::cout << text;
}

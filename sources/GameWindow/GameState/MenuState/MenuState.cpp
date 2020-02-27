#include "MenuState.h"

#include "../CharCreatingState/CharCreatingState.h"
#include "../GameLoadingState/GameLoadingState.h"
#include "../SettingsState/SettingsState.h"

MenuState::MenuState() {
}

MenuState::~MenuState() {
}

GameState* MenuState::execute() {

    this->displayText("It's menu of my fantastic rogue-like game!\n");
    this->displayText("1. Create a new character\n");
    this->displayText("2. Load existing game\n");
    this->displayText("3. Settings\n");
    this->displayText("4. Exit\n\n");

    std::string userInput = this->getInput();
    this->displayText("\n");

    if(userInput == "1") {
        return new CharCreatingState();
    }
    if(userInput == "2") {
        return new GameLoadingState();
    }
    if(userInput == "3") {
        return new SettingsState();
    }
    if(userInput == "4") {
        std::exit(0);
    }
}

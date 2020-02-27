#include "TextGameWindow.h"

TextGameWindow::TextGameWindow(): windowIsOpen(true), currentState(new MenuState()) { }

TextGameWindow::~TextGameWindow() { }

void TextGameWindow::show() {
    sf::Clock clock;
    while(windowIsOpen) {
        GameState* newState = this->currentState->execute();
        if(newState != nullptr) {
            delete this->currentState;
            this->changeState(newState);
        }
    }
}

void TextGameWindow::changeState(GameState* newState) {
    this->currentState = newState;
}

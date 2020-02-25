#include "TextGameWindow.h"

TextGameWindow::TextGameWindow(): windowIsOpen(true), currentState(GameState::INITIALIZATION) { }

TextGameWindow::~TextGameWindow() { }

void TextGameWindow::show() {
    sf::Clock clock;

    this->drawInterface(this->getInterface());

    while(windowIsOpen) {
        this->waitInput();
        this->drawInterface(this->getInterface());
    }
}

void TextGameWindow::waitInput() {
    std::string data;
    std::getline(std::cin, data);

    switch(currentState) {
    case GameState::INITIALIZATION:
        this->currentState = GameState::MAIN;
    default:
        break;
    }
}

std::string TextGameWindow::getInterface() {
    switch(this->currentState) {
    case GameState::INITIALIZATION:
        return "Добро пожаловать в мою игру! Для начала нажмите любую кнопку!";
    case GameState::MAIN:
        return "Желаете ли вы создать нового персонажа? Если желаете - нажмите кнопку g";
    default:
        return "Undefined";
    }
}

void TextGameWindow::drawInterface(std::string interface) {
    std::cout << interface;
}

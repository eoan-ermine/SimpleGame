#include "AbstractGameWindow.h"

AbstractGameWindow::AbstractGameWindow() { }

AbstractGameWindow::~AbstractGameWindow() { }

Game* AbstractGameWindow::getGame() {
    return &(this->game);
}

void AbstractGameWindow::everyTick() {
    this->game.update();
}

void AbstractGameWindow::loadResources() { }

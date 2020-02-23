#include "TextGameWindow.h"

TextGameWindow::TextGameWindow(): windowIsOpen(true) { }

TextGameWindow::~TextGameWindow() { }

void TextGameWindow::show() {
	sf::Clock clock;
	while(windowIsOpen) { }
}

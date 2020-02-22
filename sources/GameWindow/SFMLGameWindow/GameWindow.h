#pragma once

#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../../Utility/LinesVector.h"
#include "../AbstractGameWindow/AbstractGameWindow.h"

class GameWindow: public AbstractGameWindow {
    sf::RenderWindow window;
    sf::Font font;

    LinesVector guiBorder;
    sf::Text inventoryLabel;
public:
    GameWindow();
    ~GameWindow();

    void loadResources();
    void drawGUIBorders();
    void drawLabels();

    void show();
};

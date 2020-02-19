#pragma once

#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Utility/LinesVector.h"

class GameWindow {
    sf::RenderWindow window;
    sf::Font font;

    LinesVector guiBorder;

    sf::Text inventoryLabel;
public:
    GameWindow();
    ~GameWindow();

    void everyTick();

    void drawGUIBorders();
    void drawLabels();

    void show();
};

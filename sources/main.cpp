#include <SFML/Graphics.hpp>
#include "Utility/LinesVector.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SimpleGame");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        LinesVector vec({sf::Vertex(sf::Vector2f(0.0f, 500.0f)), sf::Vertex(sf::Vector2f(800.0f, 500.0f)), sf::Vertex(sf::Vector2f(600.0f, 500.0f)), sf::Vertex(sf::Vector2f(600.0f, 200.0f)), sf::Vertex(sf::Vector2f(600.0f, 200.0f)), sf::Vertex(sf::Vector2f(800.0f, 200.0f)), sf::Vertex(sf::Vector2f(600.0f, 200.0f)), sf::Vertex(sf::Vector2f(600.0f, 0.0f))});
        window.draw(vec);

        window.display();
    }
    return 0;
}

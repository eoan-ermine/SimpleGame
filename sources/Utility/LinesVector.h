#pragma once

#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <iostream>

class LinesVector: public sf::Drawable {
private:
    std::vector<sf::Vertex> vertices;
public:
    LinesVector() { }
    LinesVector(std::vector<sf::Vertex> vertices): vertices(std::move(vertices)) {
        unsigned size = vertices.size();
        if(size % 2 != 0 or not size) {
            throw std::length_error("Bad vertices size: " + std::to_string(size));
        }
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for(auto it = vertices.begin(); it < vertices.end() - 1; it += 2) {
            sf::Vertex arr[] = { *it, *(it + 1) };
            target.draw(arr, 2, sf::Lines, states);
        }
    }
    void operator=(std::vector<sf::Vertex> vertices) {
        unsigned size = vertices.size();
        if(size % 2 != 0 or not size) {
            throw std::length_error("Bad vertices size: " + std::to_string(size));
        }
        this->vertices = std::move(vertices);
    }
};

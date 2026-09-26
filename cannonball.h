#pragma once

#include <SFML/Graphics.hpp>
#include "mouse.h"
#include "math_utils.h"

class Cannonball {
    protected:
        sf::Sprite sprite;
        unsigned int minX,maxX,minY,maxY;
        double angle;
        bool use;
    public:
        Cannonball(sf::RenderWindow& window, const sf::Texture& texture, sf::Vector2f pos, double angle);
        void draw(sf::RenderWindow& window);
        void move(sf::RenderWindow& window, Mouse& mouse);
        bool used();
};
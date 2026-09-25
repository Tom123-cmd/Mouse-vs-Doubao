#pragma once

#include <SFML/Graphics.hpp>

class Doubao {
    protected:
        sf::Texture texture;
        sf::Texture texture_death;
        sf::Sprite sprite;
        unsigned int minX,maxX,minY,maxY;
        sf::Vector2f inToWindow(sf::Vector2f pos);
        int HP = 100;
    public:
        Doubao(sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void move(sf::RenderWindow& window);
        int getHP();
};
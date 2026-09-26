#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "cannonball.h"
#include "mouse.h"
#include "math_utils.h"

class Doubao {
    protected:
        sf::Texture texture;
        sf::Texture texture_death;
        sf::Texture texture_cannonball;
        sf::Sprite sprite;
        unsigned int minX,maxX,minY,maxY;
        sf::Vector2f inToWindow(sf::Vector2f pos);
        int HP = 100;
        std::vector<Cannonball> cannonballs; // 存储所有的炮弹
        sf::Clock clock;
        sf::Time lastCannonballTime = sf::Time::Zero;
        sf::Time cannonballInterval = sf::seconds(0.8f);
    public:
        Doubao(sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void move(sf::RenderWindow& window, Mouse& mouse);
        int getHP();
};
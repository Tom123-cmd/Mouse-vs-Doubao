#pragma once

#include <SFML/Graphics.hpp>

class Mouse {
    protected:
        int x, y; // 鼠标位置
        int HP;
    public:
        Mouse();
        sf::Vector2i getPosition();
        int getHP();
        void addHP(int amount);
        void updatePosition(sf::RenderWindow& window);
};
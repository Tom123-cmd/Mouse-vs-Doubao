#include "mouse.h"

Mouse::Mouse(){
    x = 0;
    y = 0;
    HP = 100;
}

sf::Vector2i Mouse::getPosition() {
    return sf::Vector2i(x, y);
}

int Mouse::getHP() {
    return HP;
}

void Mouse::addHP(int amount) {
    HP += amount;
    if (HP > 100) {
        HP = 100; // 最大生命值为 100
    }
    if (HP < 0) {
        HP = 0; // 最小生命值为 0
    }
}

void Mouse::updatePosition(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    x = mousePos.x;
    y = mousePos.y;
}
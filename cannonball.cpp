#include "cannonball.h"

const double kPi = 3.14159265358979323846;

Cannonball::Cannonball(sf::RenderWindow& window, const sf::Texture& texture, sf::Vector2f pos, double angle)
    : sprite(texture)
{
    Cannonball::minX = sprite.getGlobalBounds().size.x / 2.f;
    Cannonball::maxX = window.getSize().x - sprite.getGlobalBounds().size.x / 2.f;
    Cannonball::minY = sprite.getGlobalBounds().size.y / 2.f;
    Cannonball::maxY = window.getSize().y - sprite.getGlobalBounds().size.y / 2.f;

    sprite.setPosition(pos);
    Cannonball::angle = angle;
    Cannonball::use = true;

    sf::Vector2f size = sprite.getLocalBounds().size;
    // 将原点设为尺寸的一半，即纹理中心
    sprite.setOrigin(size / 2.f);
}

void Cannonball::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Cannonball::move() {
    if(sprite.getPosition().x < minX || sprite.getPosition().x > maxX ||
       sprite.getPosition().y < minY || sprite.getPosition().y > maxY) {
        Cannonball::use = false; // 超出边界，标记为未使用
        return; // 如果超出边界，停止移动
    }
    float dx = 5 * cos(angle * kPi / 180.0);
    float dy = 5 * sin(angle * kPi / 180.0);
    sprite.move({dx, dy});
}

bool Cannonball::used() {
    return Cannonball::use;
}
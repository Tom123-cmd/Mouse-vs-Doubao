#include "doubao.h"
#include <math.h>
#include <iostream>

Doubao::Doubao(sf::RenderWindow& window)
    : texture("res/doubao.png")   // SFML 3 支持从文件构造 Texture 
    , texture_death("res/doubao_death.png")
    , texture_cannonball("res/cannonball.png")
    , sprite(texture)         // 关键：Sprite 必须用 Texture 构造
{
    sprite.setScale({0.25f, 0.25f});
    Doubao::minX = sprite.getGlobalBounds().size.x / 2.f;
    Doubao::maxX = window.getSize().x - sprite.getGlobalBounds().size.x / 2.f;
    Doubao::minY = sprite.getGlobalBounds().size.y / 2.f;
    Doubao::maxY = window.getSize().y - sprite.getGlobalBounds().size.y / 2.f;

    // 获取本地边界尺寸（已经是 sf::Vector2f）
    sf::Vector2f size = sprite.getLocalBounds().size;
    // 将原点设为尺寸的一半，即纹理中心
    sprite.setOrigin(size / 2.f);
}

void Doubao::draw(sf::RenderWindow& window) {
    for (auto& cannonball : cannonballs) {
        if (cannonball.used()) {
            cannonball.draw(window);
        }
    }
    window.draw(sprite);
}

sf::Vector2f Doubao::inToWindow(sf::Vector2f pos){
    if(pos.x < minX) pos.x = minX;
    if(pos.x > maxX) pos.x = maxX;
    if(pos.y < minY) pos.y = minY;
    if(pos.y > maxY) pos.y = maxY;
    return pos;
}

void Doubao::move(sf::RenderWindow& window, Mouse& mouse) {
    if (HP <= 0) {
        sprite.setTexture(texture_death);
        cannonballs.clear(); // 清空所有炮弹
        return; // 如果 HP 为 0 或更低，停止移动
    }

    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;
    // std::cout << "Mouse Position: (" << mouseX << ", " << mouseY << ")" << std::endl;
    double dis = getDis(mouseX, mouseY, sprite.getPosition().x, sprite.getPosition().y);
    double angle = calcAngle(sprite.getPosition().x, sprite.getPosition().y, mouseX, mouseY);
    double moveDis = (200 - dis) * 0.05 * -1;

    float dx = static_cast<float>(moveDis * cos(angle * kPi / 180.0));
    float dy = static_cast<float>(moveDis * sin(angle * kPi / 180.0));

    sprite.move({dx, dy});
    sprite.setPosition(inToWindow(sprite.getPosition()));
    sprite.setRotation(sf::degrees(angle));

    if (dis < 45) {
        HP--;
    }

    if(clock.getElapsedTime() - lastCannonballTime >= cannonballInterval) {
        cannonballs.emplace_back(window, texture_cannonball, sprite.getPosition(), angle);
        lastCannonballTime = clock.getElapsedTime();
    }

    for (int i = 0; i < cannonballs.size(); ++i) {
        if (i < 0 || i >= cannonballs.size()) {
            continue; // 确保索引在有效范围内
        }
        if (!cannonballs[i].used()) {
            cannonballs.erase(cannonballs.begin() + i);
            --i; // 调整索引以避免跳过下一个元素
        }
    }

    for (auto& cannonball : cannonballs) {
        if (cannonball.used()) {
            cannonball.move(window, mouse);
        }
    }
}

int Doubao::getHP() {
    return HP;
}
#include "doubao.h"
#include <math.h>
#include <iostream>

constexpr double kPi = 3.14159265358979323846;

Doubao::Doubao(sf::RenderWindow& window)
    : texture("doubao.png")   // SFML 3 支持从文件构造 Texture 
    , texture_death("doubao_death.png")
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
    window.draw(sprite);
}

double getDis(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double calcAngle(double xa, double ya, double xb, double yb)
{
    double dx = xb - xa;
    double dy = yb - ya;

    // 坐标轴特殊情况
    if (dx == 0)
    {
        if (dy > 0) return 90.0;
        if (dy < 0) return 270.0;
        return 0.0; // A、B重合
    }

    // atan2(dy, dx) 返回 [-π, π] 弧度
    double rad = atan2(dy, dx);
    double deg = rad * 180.0 / kPi; // 转角度

    if (deg < 0)
        deg += 360.0;

    return deg;
}

sf::Vector2f Doubao::inToWindow(sf::Vector2f pos){
    if(pos.x < minX) pos.x = minX;
    if(pos.x > maxX) pos.x = maxX;
    if(pos.y < minY) pos.y = minY;
    if(pos.y > maxY) pos.y = maxY;
    return pos;
}

void Doubao::move(sf::RenderWindow& window) {
    if (HP <= 0) {
        sprite.setTexture(texture_death);
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
}

int Doubao::getHP() {
    return HP;
}
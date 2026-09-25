#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>

#include "doubao.h"

#include <iostream>

#ifdef SFML_SYSTEM_WINDOWS
#include <windows.h>
#include <imm.h>
#pragma comment(lib, "imm32.lib")

// 存储旧的输入上下文，以便恢复
static HIMC g_hOldIMC = nullptr;

void disableIME(sf::Window& window) {
    // 1. 获取原生窗口句柄
    // getNativeHandle() 返回 sf::WindowHandle，在 Windows 上就是 HWND
    HWND hwnd = static_cast<HWND>(window.getNativeHandle());
    
    // 2. 解除窗口与输入法的关联
    g_hOldIMC = ImmAssociateContext(hwnd, NULL);
}

// 可选：在窗口失去焦点或关闭时恢复输入法
void restoreIME(sf::Window& window) {
    if (g_hOldIMC) {
        HWND hwnd = static_cast<HWND>(window.getNativeHandle());
        ImmAssociateContext(hwnd, g_hOldIMC);
        g_hOldIMC = nullptr;
    }
}
#endif

int main()
{
    sf::Font font;
    if (!font.openFromFile("res/Inter-var-2.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
        return -1;
    }

    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "Mouse vs Doubao");
    window.setFramerateLimit(120);
    sf::Text doubaoHP(font);
    doubaoHP.setPosition({10, 10});
    sf::Text tips(font);
    tips.setPosition({10, 600 - 40});
    tips.setString("Move the mouse to control Doubao.\nWhen Doubao's HP reaches 0, it will stop moving.");
    tips.setCharacterSize(17);

    bool windowFocused = false;
    if (window.hasFocus()) {
        // 窗口当前拥有焦点
        windowFocused = true;
        disableIME(window);
    }

    Doubao doubao(window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (event->is<sf::Event::FocusGained>()) {
                windowFocused = true;
                disableIME(window);   // 获得焦点时禁用输入法
            }
            else if (event->is<sf::Event::FocusLost>()) {
                windowFocused = false;
                restoreIME(window);   // 失去焦点时恢复输入法
            }
        }

        doubao.move(window);
        doubaoHP.setString("Doubao HP: " + std::to_string(doubao.getHP()));

        window.clear(sf::Color(0, 0, 0));
        doubao.draw(window);
        window.draw(doubaoHP);
        window.draw(tips);
        window.display();
    }

    return 0;
}

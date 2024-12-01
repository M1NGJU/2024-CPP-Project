#ifndef STAGE1_7_4_H
#define STAGE1_7_4_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"
#include "stage1-7-5.h"
#include "stage1-7-7.h"

class stage1_7_4 {
private:
    static Heart heart;

public:
    static void increaseHeart(int amount) {
        heart.increase(amount);
    }

    static void decreaseHeart(int amount) {
        heart.decrease(amount);
    }

    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/hackwon1.png")) {
            std::cerr << "Failed to load background image!" << std::endl;
            return -1;
        }

        sf::Texture yukiTexture;
        if (!yukiTexture.loadFromFile("imgs/stage1/yuki1.png")) {
            std::cerr << "Failed to load yuki image!" << std::endl;
            return -1;
        }

        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/stage1/RectanglePink.png")) {
            std::cerr << "Failed to load Rectangle image!" << std::endl;
            return -1;
        }

        sf::Texture RectangleTexture2;
        if (!RectangleTexture2.loadFromFile("imgs/stage1/RectanglePink.png")) {
            std::cerr << "Failed to load RectanglePink2 image!" << std::endl;
            return -1;
        }

        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
            return -1;
        }

        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"재수?");
        text1.setCharacterSize(40);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(1200.f, 400.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"재시도하다요!! 맞죠?");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(1100.f, 600.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"유키 호감도 : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite yukiSprite(yukiTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite RectangleSprite2(RectangleTexture2);

        yukiSprite.setPosition(3.f, 1.f);
        RectangleSprite.setPosition(870.f, 350.f);
        RectangleSprite2.setPosition(870.f, 550.f);

        RectangleSprite.setScale(0.8f, 0.9f);
        RectangleSprite2.setScale(0.8f, 0.9f);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    return 0;
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        if (RectangleSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            std::cout << "Rectangle 1 클릭됨: 호감도 상승" << std::endl;
                            increaseHeart(10);
                            return 43;
                        }

                        if (RectangleSprite2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            std::cout << "Rectangle 2 클릭됨: 호감도 감소" << std::endl;
                            decreaseHeart(10);
                            return 45;
                        }
                    }
                }
            }

            window.clear(sf::Color::White);
            window.draw(backgroundSprite);
            window.draw(yukiSprite);
            window.draw(RectangleSprite);
            window.draw(RectangleSprite2);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.display();
        }

        return 0;
    }
};

Heart stage1_7_4::heart(50);

#endif

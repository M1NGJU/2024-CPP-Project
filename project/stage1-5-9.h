#ifndef STAGE1_5_9_H
#define STAGE1_5_9_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Heart.h"
#include "stage1-6.h"

class stage1_5_9 {
public:
    static Heart heart;

    static int run(sf::RenderWindow& window) {
        window.setTitle(L"stage1-5-9 (°­¹Î)");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        sf::Texture kangminTexture;
        if (!kangminTexture.loadFromFile("imgs/stage1/kangmin1.png")) {
            return -1;
        }

        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1;
        }

        sf::Text text1(L"È£°¨µµ »ó½Â", font, 100);
        text1.setFillColor(sf::Color::Red);
        text1.setPosition(700.f, 500.f);

        sf::Text text2(L"°­¹Î È£°¨µµ : " + std::to_wstring(heart.getValue()), font, 30);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite kangminSprite(kangminTexture);

        backgroundSprite.setScale(
            window.getSize().x / backgroundTexture.getSize().x,
            window.getSize().y / backgroundTexture.getSize().y
        );
        kangminSprite.setPosition(40.f, 280.f);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "Mouse clicked, switching to stage1-6..." << std::endl;
                        return 29; // stage1-6À¸·Î ÀÌµ¿
                    }
                }

            }

            window.clear(sf::Color::White);
            window.draw(backgroundSprite);
            window.draw(kangminSprite);
            window.draw(text1);
            window.draw(text2);
            window.display();
        }
        return 0;
    }
};

Heart stage1_5_9::heart(60);

#endif // STAGE1_5_9_H

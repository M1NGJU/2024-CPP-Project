#ifndef STAGE1_5_6_H
#define STAGE1_5_6_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Heart.h"

class stage1_5_6 {
public:
    static Heart heart;

    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-5-6 (°­¹Î)");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/school1.png")) {
            return -1;
        }

        sf::Texture kangminTexture;
        if (!kangminTexture.loadFromFile("imgs/stage1/kangmin1.png")) {
            return -1;
        }

        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            std::cerr << "Failed to load Rectangle image!" << std::endl;
            return -1;
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            std::cerr << "Failed to load Polygon image!" << std::endl;
            return -1;
        }

        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1;
        }


        sf::Text text1(L"°­¹Î", font, 33);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(330.f, 860.f);

        sf::Text text2(L"¤¾¤¾", font, 40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        sf::Text text3(L"°­¹Î È£°¨µµ : " + std::to_wstring(heart.getValue()), font, 30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite kangminSprite(kangminTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f);
        RectangleSprite.setPosition(310.f, 850.f);
        PolygonSprite.setPosition(1530.f, 927.f);

        backgroundSprite.setScale(
            window.getSize().x / backgroundTexture.getSize().x,
            window.getSize().y / backgroundTexture.getSize().y
        );
        kangminSprite.setPosition(40.f, 280.f);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 28; // ³Ñ¾î°¡±â
                    }
                }
            }

            window.clear(sf::Color::White);
            window.draw(backgroundSprite);
            window.draw(kangminSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.display();
        }
        return 0;
    }
};

Heart stage1_5_6::heart(50);

#endif // STAGE1_5_6_H

#ifndef STAGE1_6_7_H
#define STAGE1_6_7_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"

class stage1_6_7 {
private:
	static Heart heart;
public:
	static int run(sf::RenderWindow& parentWindow) {
		sf::RenderWindow& window = parentWindow;
		window.setTitle(L"stage1_6_5(용준)");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/ground1.png")) {
            return -1;
        }

        sf::Texture yangjunTexture;
        if (!yangjunTexture.loadFromFile("imgs/stage1/yangjun1.png")) {
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

        sf::Text text1(L"용준", font, 33);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(330.f, 860.f);

        sf::Text text2(L"헐,, 우리 다음에 데이트 하는거야?", font, 40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        sf::Text text3(L"용준 호감도 : " + std::to_wstring(heart.getValue()), font, 30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite yangjunSprite(yangjunTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f);
        RectangleSprite.setPosition(310.f, 850.f);
        PolygonSprite.setPosition(1530.f, 927.f);

        backgroundSprite.setScale(
            window.getSize().x / backgroundTexture.getSize().x,
            window.getSize().y / backgroundTexture.getSize().y
        );
        yangjunSprite.setPosition(3.f, 130.f);

        //while
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 마우스 클릭 이벤트 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 마우스 위치 얻기
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    }
                }
            }

            window.clear(sf::Color::White);
            window.draw(backgroundSprite);
            window.draw(yangjunSprite);
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


Heart stage1_6_7::heart(60);
#endif
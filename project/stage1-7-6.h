#ifndef STAGE1_7_6_H
#define STAGE1_7_6_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"

class stage1_7_6 {
private:
	static Heart heart;

public:
	static int run(sf::RenderWindow& parentWindow) {
		sf::RenderWindow& window = parentWindow;
		window.setTitle(L"stage1_7_6(유키)");

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

        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1;
        }

        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"호감도 상승");
        text1.setCharacterSize(100);
        text1.setFillColor(sf::Color::Red);
        text1.setPosition(700.f, 500.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"유키 호감도 : " + std::to_wstring(heart.getValue()));
        text2.setCharacterSize(30);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite yukiSprite(yukiTexture);

        yukiSprite.setPosition(3.f, 1.f);

        //while
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 47;
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 및 스프라이트 그리기
            window.draw(backgroundSprite);
            window.draw(yukiSprite);
            window.draw(text1);
            window.draw(text2);

            // 화면 출력
            window.display();
        }

        return 0;
	}
};
Heart stage1_7_6::heart(60);

#endif
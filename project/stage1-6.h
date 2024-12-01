#ifndef STAGE1_6_H
#define STAGE1_6_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "stage1-6-1.h"

class stage1_6 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-6(용준)");

        // 배경 텍스처 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/school1.png")) {
            std::cerr << "배경 텍스처 로드 실패!" << std::endl;
            return -1;
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            std::cerr << "폰트 로드 실패!" << std::endl;
            return -1;
        }

        // 텍스트 생성
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"점심시간");
        text1.setCharacterSize(100);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(800.f, 500.f);

        sf::Sprite backgroundSprite(backgroundTexture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    return 0;  // 창 닫기

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "마우스 클릭, 다음 stage로 이동" << std::endl;
                        return 30;  // stage1-6-1로 전환
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 및 텍스트 출력
            window.draw(backgroundSprite);
            window.draw(text1);

            // 화면 출력
            window.display();
        }

        return 0;
    }
};

#endif // STAGE1_6_H

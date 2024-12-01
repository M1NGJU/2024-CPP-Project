#ifndef STAGE1_6_4_H
#define STAGE1_6_4_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"
#include "stage1-6-5.h"

class stage1_6_4 {
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
        window.setTitle(L"stage1_6_4(용준)");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/ground1.png")) {
            std::cerr << "Failed to load background image!" << std::endl;
            return -1;
        }

        // 캐릭터 이미지 로드
        sf::Texture yangjunTexture;
        if (!yangjunTexture.loadFromFile("imgs/stage1/yangjun1.png")) {
            std::cerr << "Failed to load kangmin image!" << std::endl;
            return -1;
        }

        // 버튼 이미지 로드
        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/stage1/RectanglePink.png")) {
            std::cerr << "Failed to load RectanglePink image!" << std::endl;
            return -1;
        }

        sf::Texture RectangleTexture2;
        if (!RectangleTexture2.loadFromFile("imgs/stage1/RectanglePink.png")) {
            std::cerr << "Failed to load RectanglePink2 image!" << std::endl;
            return -1;
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
            return -1;
        }

        // 텍스트 생성
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"응 좋아! 산책하자");
        text1.setCharacterSize(40);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(1100.f, 400.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"미안,,, 나 다음 수행평가,, 나중에 같이 산책하자!");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(900.f, 600.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"용준 호감도 : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        // 스프라이트 설정
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite yangjunSprite(yangjunTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite RectangleSprite2(RectangleTexture2);

        yangjunSprite.setPosition(50.f, 125.f);
        RectangleSprite.setPosition(870.f, 350.f);
        RectangleSprite2.setPosition(870.f, 550.f);

        RectangleSprite.setScale(0.8f, 0.9f);
        RectangleSprite2.setScale(0.8f, 0.9f);

        yangjunSprite.setPosition(3.f, 130.f);

        // while
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 마우스 위치 얻기
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // 버튼 클릭 확인
                        if (RectangleSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            std::cout << "첫 번째 버튼 클릭, 페이지 상태 변경!" << std::endl;
                            // 호감도 감소
                            decreaseHeart(10); // 5에서 10으로 변경
                            return 34; // 페이지 상태 변경
                        }
                    }
                }

            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(yangjunSprite);
            window.draw(RectangleSprite);
            window.draw(RectangleSprite2);

            // 텍스트 그리기
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);

            window.display();
        }

        return 0;
    }
};
Heart stage1_6_4::heart(50);
#endif

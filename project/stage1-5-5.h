
#ifndef STAGE1_5_5_H
#define STAGE1_5_5_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"
#include "stage1-5-6.h"
#include "stage1-5-7.h"
// 선택

class stage1_5_5 {
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
        window.setTitle(L"stage1_5_5(강민)");

        // 배경 이미지 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            std::cerr << "Failed to load background image!" << std::endl;
            return -1;
        }

        // 캐릭터 이미지 로드
        sf::Texture kangminTexture;
        if (!kangminTexture.loadFromFile("imgs/stage1/kangmin1.png")) {
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
        text1.setString(L"응! 그래!");
        text1.setCharacterSize(40);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(1200.f, 400.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"미안.. 나 다른 친구랑 앉기로 해서..");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(1020.f, 600.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"강민 호감도 : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        // 스프라이트 설정
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite kangminSprite(kangminTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite RectangleSprite2(RectangleTexture2);

        kangminSprite.setPosition(50.f, 125.f);
        RectangleSprite.setPosition(870.f, 350.f);
        RectangleSprite2.setPosition(870.f, 550.f);

        RectangleSprite.setScale(0.8f, 0.9f);
        RectangleSprite2.setScale(0.8f, 0.9f);

        kangminSprite.setPosition(40.f, 280.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // 첫 번째 버튼 클릭 처리
                        if (RectangleSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            increaseHeart(10);
                            stage1_5_6::heart = heart;
                            return 25;
                        }

                        // 두 번째 버튼 클릭 처리
                        if (RectangleSprite2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            decreaseHeart(10);
                            stage1_5_7::heart = heart;
                            return 26;
                        }
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(kangminSprite);
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

// 호감도 초기값 설정
Heart stage1_5_5::heart(50);

#endif

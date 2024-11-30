#ifndef STAGE1_3_H
#define STAGE1_3_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"  // Heart 클래스 포함

class stage1_3 {
private:
    static Heart heart;  // Heart 클래스의 인스턴스

public:
    // 호감도 증가
    static void increaseHeart(int amount) {
        heart.increase(amount);
    }

    // 호감도 감소
    static void decreaseHeart(int amount) {
        heart.decrease(amount);
    }

    // 화면 렌더링
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1(환웅)");

        // 배경 이미지 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        // 환웅 캐릭터 이미지 로드
        sf::Texture hwanwoongTexture;
        if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
            return -1;
        }

        // 사각형 버튼 이미지 로드
        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/stage1/RectanglePink.png")) {
            return -1;
        }

        sf::Texture RectangleTexture2;
        if (!RectangleTexture2.loadFromFile("imgs/stage1/RectanglePink.png")) {
            return -1;
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1;
        }

        // 텍스트 생성
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"미안... 늦었지 빨리 가자");
        text1.setCharacterSize(40);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(1080.f, 400.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"ㅋㅋㅋ새학기 지각 가보자고~");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(1050.f, 600.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"환웅 호감도 : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        // 스프라이트 설정
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite hwanwoongSprite(hwanwoongTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite RectangleSprite2(RectangleTexture2);

        hwanwoongSprite.setPosition(50.f, 125.f);
        RectangleSprite.setPosition(870.f, 350.f);
        RectangleSprite2.setPosition(870.f, 550.f);

        RectangleSprite.setScale(0.8f, 0.9f);
        RectangleSprite2.setScale(0.8f, 0.9f);

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
                            decreaseHeart(10);
                        }

                        // 두 번째 버튼 클릭 처리
                        if (RectangleSprite2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            increaseHeart(10);
                        }

                        // 호감도 텍스트 업데이트
                        text3.setString(L"환웅 호감도 : " + std::to_wstring(heart.getValue()));
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(hwanwoongSprite);
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
Heart stage1_3::heart(50);

#endif

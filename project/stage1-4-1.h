#ifndef STAGE1_4_1_H
#define STAGE1_4_1_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"  // Heart 클래스 포함

class stage1_4_1 {
public:
    static Heart heart;  // Heart 클래스의 인스턴스 (외부에서 초기화)

    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-4-1(환웅)");

        // 이미지 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1; // 이미지 로드 실패
        }

        sf::Texture hwanwoongTexture;
        if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
            return -1; // 이미지 로드 실패
        }

        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1; // 이미지 로드 실패
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1; // 이미지 로드 실패
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // 사용할 글꼴 경로
            return -1; // 글꼴 로드 실패
        }

        // 텍스트 생성
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"환웅");
        text1.setCharacterSize(33);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(330.f, 860.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"뭐래.. 빨리 가자");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"환웅 호감도 : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite hwanwoongSprite(hwanwoongTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f);
        RectangleSprite.setPosition(310.f, 850.f);
        PolygonSprite.setPosition(1530.f, 927.f);

        // 배경 이미지 크기 조정 (필요시)
        backgroundSprite.setScale(
            window.getSize().x / backgroundTexture.getSize().x,
            window.getSize().y / backgroundTexture.getSize().y
        );

        hwanwoongSprite.setPosition(50.f, 125.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // 마우스 클릭 이벤트 추가
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // 다음 화면으로 넘어가는 클릭 영역 추가 (예: PolygonSprite)
                        if (PolygonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            // 다음 화면으로 전환 (예: return 19)
                            return 19;
                        }
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);
            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(hwanwoongSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3); // 호감도 텍스트 그리기
            // 화면 출력
            window.display();
        }
        return 0; // 추가된 return 0
    }
};

// 호감도 초기값 설정 (외부에서 초기화)
Heart stage1_4_1::heart(50);

#endif // STAGE1_4_1_H

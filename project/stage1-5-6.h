#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"  // Heart 클래스 포함
#include "stage1-5-9.h"  // stage1-5-9 클래스 포함

class stage1_5_6 {
public:
    static Heart heart;  // Heart 클래스의 인스턴스 (외부에서 초기화)

    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-5-6(강민)");

        // 배경 텍스처 로드
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
            return -1; // 이미지 로드 실패 시 종료
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1; // 이미지 로드 실패 시 종료
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1; // 글꼴 로드 실패 시 종료
        }

        // 텍스트 생성
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"강민");
        text1.setCharacterSize(33);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(330.f, 860.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"ㅎㅎ");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"강민 호감도 : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite kangminSprite(kangminTexture);
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

        kangminSprite.setPosition(40.f, 280.f);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed)
                    window.close();

                // 마우스 클릭 이벤트 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return stage1_5_9::run(window);  // stage1-5-9 실행
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(kangminSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3); // 호감도 텍스트 그리기

            window.display();
        }
        return 0;
    }
};

// 호감도 초기값 설정
Heart stage1_5_6::heart(50);

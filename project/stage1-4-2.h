#ifndef STAGE1_4_2_H
#define STAGE1_4_2_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"  // Heart 클래스 포함

class stage1_4_2 {
public:
    static Heart heart;  // Heart 클래스의 인스턴스 (외부에서 초기화)

    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-4-2(환웅)");

        // 배경 텍스처 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        // 환웅 이미지 텍스처 로드
        sf::Texture hwanwoongTexture;
        if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
            return -1;
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1; // 글꼴 로드 실패 시 종료
        }

        // 텍스트 생성
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"호감도 상승");
        text1.setCharacterSize(100); // 글자 크기
        text1.setFillColor(sf::Color::Red); // 글자 색상
        text1.setPosition(700.f, 500.f); // 텍스트 위치 조정

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"환웅 호감도 : " + std::to_wstring(heart.getValue()));
        text2.setCharacterSize(30);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(40.f, 30.f);

        // 스프라이트 설정
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite hwanwoongSprite(hwanwoongTexture);
        hwanwoongSprite.setPosition(50.f, 125.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed)
                    window.close();

                // 마우스 클릭 이벤트 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 20; // 필요 시 다른 페이지로 전환하도록 설정
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 스프라이트 및 텍스트 그리기
            window.draw(backgroundSprite);
            window.draw(hwanwoongSprite);
            window.draw(text1);
            window.draw(text2);

            // 화면 출력
            window.display();
        }

        return 0;
    }
};

Heart stage1_4_2::heart(50);

#endif // STAGE1_4_2_H
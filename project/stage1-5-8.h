#ifndef STAGE1_5_8_H
#define STAGE1_5_8_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Heart.h"  // Heart 클래스 포함

class stage1_5_8 {
public:
    static Heart heart;  // Heart 클래스의 인스턴스 (외부에서 초기화)

    static int run(sf::RenderWindow& window) { // parentWindow 제거
        window.setTitle(L"stage1-5-8(강민)");  // 창 제목 설정

        // 배경 이미지 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            std::cerr << "배경 이미지 로드 실패!" << std::endl;
            return -1;
        }

        // 강민 이미지 로드
        sf::Texture kangminTexture;
        if (!kangminTexture.loadFromFile("imgs/stage1/kangmin1.png")) {
            std::cerr << "강민 이미지 로드 실패!" << std::endl;
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
        text1.setString(L"호감도 하락");
        text1.setCharacterSize(100);
        text1.setFillColor(sf::Color::Red);
        text1.setPosition(700.f, 500.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"강민 호감도 : " + std::to_wstring(heart.getValue()));
        text2.setCharacterSize(30);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(40.f, 30.f);

        // 스프라이트 설정
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite kangminSprite(kangminTexture);
        kangminSprite.setPosition(40.f, 280.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "Mouse clicked, closing window..." << std::endl;
                        window.close();
                        return 0;
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 및 스프라이트 그리기
            window.draw(backgroundSprite);
            window.draw(kangminSprite);
            window.draw(text1);
            window.draw(text2);

            // 화면 출력
            window.display();
        }

        return 0;
    }
};

// 호감도 초기값 설정 (외부에서 초기화)
Heart stage1_5_8::heart(40);

#endif // STAGE1_5_8_H

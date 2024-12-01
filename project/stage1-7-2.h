#ifndef STAGE1_7_2_H
#define STAGE1_7_2_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

class stage1_7_2 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-7-1(유키)");
        // 배경 텍스처 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/hackwon1.png")) {
            std::cout << "배경 텍스처 로드 실패!" << std::endl;
            return -1;
        }

        sf::Texture yukiTexture;
        if (!yukiTexture.loadFromFile("imgs/stage1/yuki1.png")) {
            std::cout << "유키 이미지 로드 실패!" << std::endl;
            return -1;
        }

        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            std::cout << "사각형 이미지 로드 실패!" << std::endl;
            return -1;
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            std::cout << "다각형 이미지 로드 실패!" << std::endl;
            return -1;
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            std::cout << "글꼴 로드 실패!" << std::endl;
            return -1;
        }

        // 텍스트 생성
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"정민 레이디");
        text1.setCharacterSize(33);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(330.f, 860.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"네.. 빨리 오셨네요");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"유키 호감도 : 50");
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite yukiSprite(yukiTexture);
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

        yukiSprite.setPosition(3.f, 1.f);

        // while문

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed)
                    return 0;
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(yukiSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);

            // 화면 출력
            window.display();
        }

        return 0;
    }
};

#endif
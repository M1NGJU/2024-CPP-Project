#ifndef STAGE1_7_H
#define STAGE1_7_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

class stage1_7 {
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
        text1.setString(L"학원 가는 중");
        text1.setCharacterSize(100);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(750.f, 500.f);

        sf::Sprite backgroundSprite(backgroundTexture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    return 0;  // 창 닫기
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


#endif
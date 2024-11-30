#ifndef STAGE1_5_1_H
#define STAGE1_5_1_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

class stage1_5_1 {
public:
	static int run(sf::RenderWindow& parentWindow) {
		sf::RenderWindow& window = parentWindow;
		window.setTitle(L"stage1-5-1(강민)");

		// 배경 텍스처 로드
		sf::Texture backgroundTexture;
		if (!backgroundTexture.loadFromFile("imgs/stage1/space.png")) {
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
        text1.setString(L"학교 가는 중");
        text1.setCharacterSize(100); // 글자 크기
        text1.setFillColor(sf::Color::Black); // 글자 색상
        text1.setPosition(700.f, 500.f); // 텍스트 위치 조정

        sf::Sprite backgroundSprite(backgroundTexture);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 스프라이트 및 텍스트 그리기
            window.draw(backgroundSprite);
            window.draw(text1);

            // 화면 출력
            window.display();
        }

        return 0;
	}
};

#endif
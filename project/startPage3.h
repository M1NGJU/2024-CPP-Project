#ifndef START_PAGE3_H
#define START_PAGE3_H

#include <SFML/Graphics.hpp>

class StartPage3 {
public:
        static int run(sf::RenderWindow & parentWindow) {
            sf::RenderWindow& window = parentWindow;
            window.setTitle("page3");

            // 텍스처 로드
            sf::Texture textTexture;
            if (!textTexture.loadFromFile("imgs/start-page1/text3.png")) {
                return -1;
            }

            sf::Texture text2Texture;
            if (!text2Texture.loadFromFile("imgs/start-page1/text4.png")) {
                return -1;
            }

            sf::Texture text3Texture;
            if (!text3Texture.loadFromFile("imgs/start-page1/text5.png")) {
                return -1;
            }

            // 스프라이트 생성
            sf::Sprite textSprite(textTexture);
            sf::Sprite text2Sprite(text2Texture);
            sf::Sprite text3Sprite(text3Texture);

            // 텍스트 스프라이트 위치 설정
            textSprite.setPosition(340.f, 350.f);
            text2Sprite.setPosition(740.f, 550.f);
            text3Sprite.setPosition(1040.f, 740.f);

            // 메인 루프
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    // 닫기 버튼 처리
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        return -1;
                    }

                    // 클릭 이벤트 처리
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            // 화면 클릭 시 startPage4로 이동
                            return 4; // startPage4 실행
                        }
                    }
                }

                // 화면 초기화
                window.clear(sf::Color::Black);

                // 스프라이트 그리기
                window.draw(textSprite);
                window.draw(text2Sprite);
                window.draw(text3Sprite);

                // 화면 출력
                window.display();
            }

            return 3; // 기본 상태 반환
    }
};

#endif // START_PAGE3_H

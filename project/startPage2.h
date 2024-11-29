#ifndef START_PAGE2_H
#define START_PAGE2_H

#include <SFML/Graphics.hpp>

class StartPage2 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        // 기존 창 사용
        sf::RenderWindow& window = parentWindow;
        window.setTitle("page2");

        // 배경 텍스처 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/start-page1/background2.png")) {
            return -1; // 이미지 로드 실패 시 종료
        }

        // 첫 번째 텍스트 텍스처 로드
        sf::Texture textTexture;
        if (!textTexture.loadFromFile("imgs/start-page1/text1.png")) {
            return -1;
        }

        // 두 번째 텍스트 텍스처 로드
        sf::Texture text2Texture;
        if (!text2Texture.loadFromFile("imgs/start-page1/text2.png")) {
            return -1;
        }

        // 스프라이트 생성
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite textSprite(textTexture);
        sf::Sprite text2Sprite(text2Texture);

        // 텍스트 스프라이트 위치 설정
        textSprite.setPosition(480.f, 500.f);
        text2Sprite.setPosition(640.f, 650.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 창 닫기 이벤트 처리
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }

                // 화면 클릭 이벤트 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 화면 클릭 시 바로 다음 페이지로 전환
                        return 3; // 또는 원하는 다음 페이지 번호
                    }
                }
            }

            // 화면 초기화 - 블랙으로 설정
            window.clear(sf::Color::Black);

            // 스프라이트 그리기
            window.draw(backgroundSprite);
            window.draw(textSprite);
            window.draw(text2Sprite);

            // 화면 출력
            window.display();
        }

        return 1;
    }
};

#endif // START_PAGE2_H

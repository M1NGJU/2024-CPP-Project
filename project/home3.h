#ifndef HOME3_H
#define HOME3_H

#include <SFML/Graphics.hpp>

class Home3 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Home3");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
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

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f); // 90% 가로, 70% 세로로 축소
        RectangleSprite.setPosition(310.f, 850.f); // 중앙에서 살짝 아래로 이동
        PolygonSprite.setPosition(1530.f, 927.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed)
                    window.close();

                // 클릭 이벤트 처리 (home4로 전환)
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 클릭된 위치가 특정 영역에 있는지 확인하고, 그에 맞는 페이지로 전환
                        if (RectangleSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                            return 8; // 클릭 시 Home4 페이지로 전환
                        }
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 이미지 그리기
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            // 화면 출력
            window.display();
        }

        return 0;
    }
};

#endif // HOME3_H
#ifndef START_PAGE1_H
#define START_PAGE1_H

#include <SFML/Graphics.hpp>

class StartPage1 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        // 기존 창 사용
        sf::RenderWindow& window = parentWindow;
        window.setTitle("page1");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/start-page1/background.png")) {
            return -1; // 이미지 로드 실패 시 종료
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

        // 사각형 크기 조정 (절반 크기로 설정)
        RectangleSprite.setScale(0.9f, 0.7f); // 90% 가로, 70% 세로로 축소

        // 중앙에서 살짝 아래로 이동
        RectangleSprite.setPosition(310.f, 850.f);

        // 폴리곤을 지정한 위치 (1637, 927)로 이동
        PolygonSprite.setPosition(1530.f, 927.f);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 창 닫기 이벤트 처리
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // 마우스 클릭 이벤트 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 마우스 클릭 좌표 얻기
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // 폴리곤 스프라이트의 글로벌 바운드 얻기
                        sf::FloatRect polygonBounds = PolygonSprite.getGlobalBounds();

                        // 마우스 클릭이 폴리곤 영역 안에 있는지 확인
                        if (polygonBounds.contains(mousePos.x, mousePos.y)) {
                            // 다음 페이지로 전환
                            return 2; // startPage2로 이동
                        }
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            // 화면 출력
            window.display();
        }

        return 1;
    }
};

#endif // START_PAGE1_H

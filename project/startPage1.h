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

        // 페이지 상태를 추적할 변수
        bool changePage = false;

        while (window.isOpen() && !changePage) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 창 닫기 이벤트 처리
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // 마우스 클릭 이벤트 추가 (선택적)
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 필요하다면 페이지 전환 로직 추가
                        changePage = true;
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

        return changePage ? 1 : 0;
    }
};

#endif // START_PAGE1_H
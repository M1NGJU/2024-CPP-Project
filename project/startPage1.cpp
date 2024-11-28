#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "page1");

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

    return 0;
}

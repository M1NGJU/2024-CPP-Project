#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "page1");

    // 배경 텍스처 로드
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/start-page1/background.png")) {
        return -1; // 이미지 로드 실패 시 종료
    }

    // 사각형 텍스처 로드
    sf::Texture RectangleTexture;
    if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
        return -1; // 이미지 로드 실패 시 종료
    }

    // 폴리곤 텍스처 로드
    sf::Texture PolygonTexture;
    if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
        return -1; // 이미지 로드 실패 시 종료
    }

    sf::Sprite backgroundSprite(backgroundTexture);
    sf::Sprite RectangleSprite(RectangleTexture);
    sf::Sprite PolygonSprite(PolygonTexture);

    // 사각형 크기 조정 (90% 가로, 70% 세로로 축소)
    RectangleSprite.setScale(0.9f, 0.7f);
    RectangleSprite.setPosition(310.f, 850.f); // 화면 아래로 이동

    // 폴리곤 위치 지정
    PolygonSprite.setPosition(1530.f, 927.f);

    // 폰트 로드
    sf::Font font;
    if (!font.loadFromFile("font/gulim.ttc")) {
        return -1;
    }

    // 텍스트 생성
    sf::Text text("정민레이디", font, 100);
    text.setFillColor(sf::Color::Black); // 텍스트 색상
    text.setStyle(sf::Text::Bold); // 텍스트 스타일 (굵게)
    text.setPosition(1920 / 2.f - text.getGlobalBounds().width / 2.f, 200.f); // 화면 중앙 상단 위치

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // 화면 초기화
        window.clear(sf::Color::White);

        // 배경 및 스프라이트 그리기
        window.draw(backgroundSprite);
        window.draw(RectangleSprite);
        window.draw(PolygonSprite);

        // 텍스트 그리기
        window.draw(text);

        // 화면 출력
        window.display();
    }

    return 0;
}

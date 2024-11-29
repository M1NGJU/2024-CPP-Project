#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 윈도우 생성 (1920x1080 크기, 제목: "SFML 윈도우")
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "stage1");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
        std::cerr << "이미지 로드 실패!" << std::endl;
        return -1;
    }

    sf::Texture hwanwoongTexture;
    if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
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
    sf::Sprite hwanwoongSprite(hwanwoongTexture);
    sf::Sprite RectangleSprite(RectangleTexture);
    sf::Sprite PolygonSprite(PolygonTexture);

    RectangleSprite.setScale(0.9f, 0.7f); // 90% 가로, 70% 세로로 축소

    // 중앙에서 살짝 아래로 이동
    RectangleSprite.setPosition(310.f, 850.f);

    PolygonSprite.setPosition(1530.f, 927.f);

    // 배경 이미지 크기 조정 (필요시)
    backgroundSprite.setScale(
        window.getSize().x / backgroundTexture.getSize().x,
        window.getSize().y / backgroundTexture.getSize().y
    );

    hwanwoongSprite.setPosition(50.f, 125.f);

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

        // 배경 그리기
        window.draw(backgroundSprite);
        window.draw(hwanwoongSprite);
        window.draw(RectangleSprite);
        window.draw(PolygonSprite);

        // 화면 출력
        window.display();
    }

    return 0;
}

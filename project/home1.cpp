#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "home");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
        return -1;
    }

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

        // 배경 이미지 그리기
        window.draw(backgroundSprite);

        // 화면 출력
        window.display();
    }

    return 0;
}

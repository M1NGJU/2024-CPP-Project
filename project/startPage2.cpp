#include <SFML/Graphics.hpp>

int main() {
    // 윈도우 생성 (800x600 크기, 제목: "SFML 윈도우")
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "page2");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/start-page1/background2.png")) {
        return -1; // 이미지 로드 실패 시 종료
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
        window.clear(sf::Color::Black);

        window.draw(backgroundSprite);

        // 화면 출력
        window.display();
    }

    return 0;
}

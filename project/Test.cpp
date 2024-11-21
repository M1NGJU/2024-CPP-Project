#include <SFML/Graphics.hpp>

int main() {
    // 윈도우 생성 (800x600 크기, 제목: "SFML 윈도우")
    sf::RenderWindow window(sf::VideoMode(1440, 1024), "SFML");

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

        // 화면 출력
        window.display();
    }

    return 0;
}

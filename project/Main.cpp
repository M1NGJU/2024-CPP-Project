#include <SFML/Graphics.hpp>
#include "start.h"       // Start 화면 헤더
#include "startPage1.h"  // Page1 화면 헤더

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Multi Screen");

    // 화면 상태 (0: Start 화면, 1: Page1 화면)
    int currentPage = 0;

    StartScreen startScreen;       // Start 화면 객체
    StartPage1 startPage1;         // Page1 화면 객체

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // 화면 전환 처리
            if (currentPage == 0) {
                if (startScreen.handleEvent(event)) {
                    currentPage = 1;  // Start 화면에서 Page1 화면으로 전환
                }
            }
        }

        // 화면 렌더링
        window.clear(sf::Color::White);

        if (currentPage == 0) {
            startScreen.render(window);  // Start 화면 렌더링
        }
        else if (currentPage == 1) {
            startPage1.render(window);  // Page1 화면 렌더링
        }

        window.display();
    }

    return 0;
}

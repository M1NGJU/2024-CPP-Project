#include <SFML/Graphics.hpp>
#include "start.h"
#include "startPage1.h"

int main() {
    // 단일 창 생성
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");

    // 첫 번째 페이지 상태 추적
    int pageState = 0;

    while (window.isOpen()) {
        // 페이지 상태에 따라 다른 페이지 실행
        switch (pageState) {
        case 0: // 시작 페이지
            pageState = StartPage::run(window);
            break;
        case 1: // 첫 번째 페이지
            pageState = StartPage1::run(window);
            break;
        default:
            window.close();
            break;
        }
    }

    return 0;
}
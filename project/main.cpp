#include <SFML/Graphics.hpp>
#include "start.h"
#include "startPage1.h"
#include "startPage2.h"
#include "startPage3.h"
#include "startPage4.h" // 추가
#include "home1.h" // home1.h 헤더 추가
#include "home2.h" 
#include "home3.h"
#include "home4.h"

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
        case 2: // 두 번째 페이지
            pageState = StartPage2::run(window);
            break;
        case 3: // 세 번째 페이지
            pageState = StartPage3::run(window);
            break;
        case 4: // 네 번째 페이지
            pageState = StartPage4::run(window); // 추가된 페이지 실행
            break;
        case 5: // home1 화면
            pageState = Home1::run(window); // home1 화면 실행
            break;
        case 6: // home2 화면
            pageState = Home2::run(window);
            break;
        case 7:
            pageState = Home3::run(window);
            break;
        case 8:
            pageState = Home4::run(window);
            break;
        default:
            window.close();
            break;
        }
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include "start.h"
#include "startPage1.h"
#include "startPage2.h"
#include "startPage3.h"
#include "startPage4.h" // 추가
#include "home1.h" // 추가
#include "home2.h" // 추가

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
            pageState = StartPage4::run(window); // StartPage4 실행
            break;
        case 5: // home1 페이지
            Home1::show(window); // home1 화면 표시
            pageState = 6; // home1 화면이 끝나면 home2 화면으로 이동
            break;
        case 6: // home2 페이지
            Home2::show(window); // home2 화면 표시
            pageState = 0; // home2 화면이 끝나면 시작 페이지로 돌아가기
            break;
        default:
            window.close();
            break;
        }
    }

    return 0;
}

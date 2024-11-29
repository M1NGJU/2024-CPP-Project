#include <SFML/Graphics.hpp>
#include "start.h"
#include "startPage1.h"
#include "startPage2.h"
#include "startPage3.h"
#include "startPage4.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");

    int pageState = 0;

    while (window.isOpen()) {

        switch (pageState) {
        case 0:
            pageState = StartPage::run(window);
            break;
        case 1:
            pageState = StartPage1::run(window);
            break;
        case 2:
            pageState = StartPage2::run(window);
            break;
        case 3:
            pageState = StartPage3::run(window);
            break;
        case 4:
            pageState = StartPage4::run(window);
            break;
        default:
            window.close();
            break;
        }

        if (pageState == -1) {  // 종료된 상태로 리턴되면
            pageState = 0;  // 0으로 초기화하여 다시 처음 화면으로 돌아감
        }
    }

    return 0;
}

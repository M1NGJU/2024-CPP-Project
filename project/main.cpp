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

        if (pageState == -1) {  // ����� ���·� ���ϵǸ�
            pageState = 0;  // 0���� �ʱ�ȭ�Ͽ� �ٽ� ó�� ȭ������ ���ư�
        }
    }

    return 0;
}

#include <SFML/Graphics.hpp>
#include "start.h"
#include "startPage1.h"

int main() {
    // ���� â ����
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");

    // ù ��° ������ ���� ����
    int pageState = 0;

    while (window.isOpen()) {
        // ������ ���¿� ���� �ٸ� ������ ����
        switch (pageState) {
        case 0: // ���� ������
            pageState = StartPage::run(window);
            break;
        case 1: // ù ��° ������
            pageState = StartPage1::run(window);
            break;
        default:
            window.close();
            break;
        }
    }

    return 0;
}
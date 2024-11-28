#include <SFML/Graphics.hpp>
#include "start.h"       // Start ȭ�� ���
#include "startPage1.h"  // Page1 ȭ�� ���

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Multi Screen");

    // ȭ�� ���� (0: Start ȭ��, 1: Page1 ȭ��)
    int currentPage = 0;

    StartScreen startScreen;       // Start ȭ�� ��ü
    StartPage1 startPage1;         // Page1 ȭ�� ��ü

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // ȭ�� ��ȯ ó��
            if (currentPage == 0) {
                if (startScreen.handleEvent(event)) {
                    currentPage = 1;  // Start ȭ�鿡�� Page1 ȭ������ ��ȯ
                }
            }
        }

        // ȭ�� ������
        window.clear(sf::Color::White);

        if (currentPage == 0) {
            startScreen.render(window);  // Start ȭ�� ������
        }
        else if (currentPage == 1) {
            startPage1.render(window);  // Page1 ȭ�� ������
        }

        window.display();
    }

    return 0;
}

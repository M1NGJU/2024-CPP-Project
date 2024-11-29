#include <SFML/Graphics.hpp>
#include "start.h"
#include "startPage1.h"
#include "startPage2.h"
#include "startPage3.h"
#include "startPage4.h" // �߰�
#include "home1.h" // home1.h ��� �߰�

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
        case 2: // �� ��° ������
            pageState = StartPage2::run(window);
            break;
        case 3: // �� ��° ������
            pageState = StartPage3::run(window);
            break;
        case 4: // �� ��° ������
            pageState = StartPage4::run(window); // �߰��� ������ ����
            break;
        case 5: // home1 ȭ��
            pageState = Home1::run(window); // home1 ȭ�� ����
            break;
        default:
            window.close();
            break;
        }
    }

    return 0;
}

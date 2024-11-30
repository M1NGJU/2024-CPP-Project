#include <SFML/Graphics.hpp>
#include <iostream> // ����� �޽����� ���� �߰�
#include "start.h"
#include "startPage1.h"
#include "startPage2.h"
#include "startPage3.h"
#include "startPage4.h"
#include "home1.h"
#include "home2.h"
#include "home3.h"
#include "home4.h"
#include "home5.h"
#include "home6.h"
#include "home7.h" // �߰�
#include "stage1.h"
#include "stage1-1.h"
#include "stage1-2.h"
#include "stage1-3.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");

    int pageState = 0;

    while (window.isOpen()) {
        std::cout << "Current pageState: " << pageState << std::endl; // ����� �޽���

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
        case 5:
            pageState = Home1::run(window);
            break;
        case 6:
            pageState = Home2::run(window);
            break;
        case 7:
            pageState = Home3::run(window);
            break;
        case 8:
            pageState = Home4::run(window);
            break;
        case 9:
            pageState = Home5::run(window);
            break;
        case 10:
            pageState = Home6::run(window);
            break;
        case 11: // pageState�� 11�� ��� Home7 ����
            pageState = Home7::run(window);
            break;
        case 12:    // stage1
            pageState = stage1::run(window);
            break;
        case 13:
            pageState = stage1_1::run(window);
            break;
        case 14:
            pageState = stage1_2::run(window);
            break;
        case 15:
            pageState = stage1_3::run(window);
        default:
            window.close();
            break;
        }
    }

    return 0;
}
#ifndef STAGE1_5_1_H
#define STAGE1_5_1_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "stage1-5-2.h"

class stage1_5_1 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-5-1(����)");

        // ��� �ؽ�ó �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/space.png")) {
            return -1;
        }

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1; // �۲� �ε� ���� �� ����
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"�б� ���� ��");
        text1.setCharacterSize(100); // ���� ũ��
        text1.setFillColor(sf::Color::Black); // ���� ����
        text1.setPosition(700.f, 500.f); // �ؽ�Ʈ ��ġ ����

        sf::Sprite backgroundSprite(backgroundTexture);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed)
                    return 21;  // Ŭ�� �� stage1-5-2�� �Ѿ
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "���콺 Ŭ��, stage1-5-2�� �̵�" << std::endl;
                        return 21; // stage1-5-2�� �Ѿ
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��������Ʈ �� �ؽ�Ʈ �׸���
            window.draw(backgroundSprite);
            window.draw(text1);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};

#endif

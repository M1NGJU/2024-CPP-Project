#ifndef STAGE1_5_8_H
#define STAGE1_5_8_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Heart.h"  // Heart Ŭ���� ����

class stage1_5_8 {
public:
    static Heart heart;  // Heart Ŭ������ �ν��Ͻ� (�ܺο��� �ʱ�ȭ)

    static int run(sf::RenderWindow& window) { // parentWindow ����
        window.setTitle(L"stage1-5-8(����)");  // â ���� ����

        // ��� �̹��� �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            std::cerr << "��� �̹��� �ε� ����!" << std::endl;
            return -1;
        }

        // ���� �̹��� �ε�
        sf::Texture kangminTexture;
        if (!kangminTexture.loadFromFile("imgs/stage1/kangmin1.png")) {
            std::cerr << "���� �̹��� �ε� ����!" << std::endl;
            return -1;
        }

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            std::cerr << "��Ʈ �ε� ����!" << std::endl;
            return -1;
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"ȣ���� �϶�");
        text1.setCharacterSize(100);
        text1.setFillColor(sf::Color::Red);
        text1.setPosition(700.f, 500.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"���� ȣ���� : " + std::to_wstring(heart.getValue()));
        text2.setCharacterSize(30);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(40.f, 30.f);

        // ��������Ʈ ����
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite kangminSprite(kangminTexture);
        kangminSprite.setPosition(40.f, 280.f);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "Mouse clicked, closing window..." << std::endl;
                        window.close();
                        return 0;
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �� ��������Ʈ �׸���
            window.draw(backgroundSprite);
            window.draw(kangminSprite);
            window.draw(text1);
            window.draw(text2);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};

// ȣ���� �ʱⰪ ���� (�ܺο��� �ʱ�ȭ)
Heart stage1_5_8::heart(40);

#endif // STAGE1_5_8_H

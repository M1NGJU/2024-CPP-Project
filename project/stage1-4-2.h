#ifndef STAGE1_4_2_H
#define STAGE1_4_2_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"  // Heart Ŭ���� ����

class stage1_4_2 {
public:
    static Heart heart;  // Heart Ŭ������ �ν��Ͻ� (�ܺο��� �ʱ�ȭ)

    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-4-2(ȯ��)");

        // ��� �ؽ�ó �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        // ȯ�� �̹��� �ؽ�ó �ε�
        sf::Texture hwanwoongTexture;
        if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
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
        text1.setString(L"ȣ���� ���");
        text1.setCharacterSize(100); // ���� ũ��
        text1.setFillColor(sf::Color::Red); // ���� ����
        text1.setPosition(700.f, 500.f); // �ؽ�Ʈ ��ġ ����

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"ȯ�� ȣ���� : " + std::to_wstring(heart.getValue()));
        text2.setCharacterSize(30);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(40.f, 30.f);

        // ��������Ʈ ����
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite hwanwoongSprite(hwanwoongTexture);
        hwanwoongSprite.setPosition(50.f, 125.f);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed)
                    window.close();

                // ���콺 Ŭ�� �̺�Ʈ ó��
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 20; // �ʿ� �� �ٸ� �������� ��ȯ�ϵ��� ����
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��������Ʈ �� �ؽ�Ʈ �׸���
            window.draw(backgroundSprite);
            window.draw(hwanwoongSprite);
            window.draw(text1);
            window.draw(text2);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};

Heart stage1_4_2::heart(50);

#endif // STAGE1_4_2_H
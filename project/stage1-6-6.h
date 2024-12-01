#ifndef STAGE1_6_6_H
#define STAGE1_6_6_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"

class stage1_6_6 {
private:
    static Heart heart;

public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;  // �θ� �����츦 window�� ����

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/ground1.png")) {
            return -1;
        }

        sf::Texture yangjunTexture;
        if (!yangjunTexture.loadFromFile("imgs/stage1/yangjun1.png")) {
            return -1;
        }

        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1;
        }

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

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite yangjunSprite(yangjunTexture);

        yangjunSprite.setPosition(3.f, 130.f);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �� ��������Ʈ �׸���
            window.draw(backgroundSprite);
            window.draw(yangjunSprite);
            window.draw(text1);
            window.draw(text2);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};

Heart stage1_6_6::heart(40);

#endif

#ifndef STAGE1_5_5_H
#define STAGE1_5_5_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"

class stage1_5_5 {
private:
    static Heart heart;

public:
    // ȣ���� ����
    static void increaseHeart(int amount) {
        heart.increase(amount);
    }

    // ȣ���� ����
    static void decreaseHeart(int amount) {
        heart.decrease(amount);
    }

    // ȭ�� ������
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1_5_5(����)");

        // ��� �̹��� �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        // ĳ���� �̹��� �ε�
        sf::Texture kangminTexture;
        if (!kangminTexture.loadFromFile("imgs/stage1/kangmin1.png")) {
            return -1;
        }

        // ��ư �̹��� �ε�
        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/stage1/RectanglePink.png")) {
            return -1;
        }

        sf::Texture RectangleTexture2;
        if (!RectangleTexture2.loadFromFile("imgs/stage1/RectanglePink.png")) {
            return -1;
        }

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            return -1;
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"��! �׷�!");
        text1.setCharacterSize(40);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(1200.f, 400.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"�̾�.. �� �ٸ� ģ���� �ɱ�� �ؼ�..");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(1020.f, 600.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"���� ȣ���� : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        // ��������Ʈ ����
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite kangminSprite(kangminTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite RectangleSprite2(RectangleTexture2);

        kangminSprite.setPosition(50.f, 125.f);
        RectangleSprite.setPosition(870.f, 350.f);
        RectangleSprite2.setPosition(870.f, 550.f);

        RectangleSprite.setScale(0.8f, 0.9f);
        RectangleSprite2.setScale(0.8f, 0.9f);

        kangminSprite.setPosition(40.f, 280.f);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // ù ��° ��ư Ŭ�� ó��
                        if (RectangleSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            increaseHeart(10);
                            return 25; // ���� ��ȯ�� ���� ��
                        }

                        // �� ��° ��ư Ŭ�� ó��
                        if (RectangleSprite2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            decreaseHeart(10);
                            return 26; // ���� ��ȯ�� ���� ��
                        }
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �׸���
            window.draw(backgroundSprite);
            window.draw(kangminSprite);
            window.draw(RectangleSprite);
            window.draw(RectangleSprite2);

            // �ؽ�Ʈ �׸���
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);

            window.display();
        }

        return 0;
    }
};

// ȣ���� �ʱⰪ ����
Heart stage1_5_5::heart(50);

#endif

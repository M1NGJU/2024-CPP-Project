#ifndef STAGE1_3_H
#define STAGE1_3_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"  // Heart Ŭ���� ����

class stage1_3 {
private:
    static Heart heart;  // Heart Ŭ������ �ν��Ͻ�

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
        window.setTitle(L"stage1(ȯ��)");

        // ��� �̹��� �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        // ȯ�� ĳ���� �̹��� �ε�
        sf::Texture hwanwoongTexture;
        if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
            return -1;
        }

        // �簢�� ��ư �̹��� �ε�
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
        text1.setString(L"�̾�... �ʾ��� ���� ����");
        text1.setCharacterSize(40);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(1080.f, 400.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"���������б� ���� �����ڰ�~");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(1050.f, 600.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"ȯ�� ȣ���� : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        // ��������Ʈ ����
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite hwanwoongSprite(hwanwoongTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite RectangleSprite2(RectangleTexture2);

        hwanwoongSprite.setPosition(50.f, 125.f);
        RectangleSprite.setPosition(870.f, 350.f);
        RectangleSprite2.setPosition(870.f, 550.f);

        RectangleSprite.setScale(0.8f, 0.9f);
        RectangleSprite2.setScale(0.8f, 0.9f);

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
                            decreaseHeart(10);
                        }

                        // �� ��° ��ư Ŭ�� ó��
                        if (RectangleSprite2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            increaseHeart(10);
                        }

                        // ȣ���� �ؽ�Ʈ ������Ʈ
                        text3.setString(L"ȯ�� ȣ���� : " + std::to_wstring(heart.getValue()));
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �׸���
            window.draw(backgroundSprite);
            window.draw(hwanwoongSprite);
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
Heart stage1_3::heart(50);

#endif

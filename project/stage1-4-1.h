#ifndef STAGE1_4_1_H
#define STAGE1_4_1_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"  // Heart Ŭ���� ����

class stage1_4_1 {
public:
    static Heart heart;  // Heart Ŭ������ �ν��Ͻ� (�ܺο��� �ʱ�ȭ)

    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-4-1(ȯ��)");

        // �̹��� �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1; // �̹��� �ε� ����
        }

        sf::Texture hwanwoongTexture;
        if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
            return -1; // �̹��� �ε� ����
        }

        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1; // �̹��� �ε� ����
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1; // �̹��� �ε� ����
        }

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // ����� �۲� ���
            return -1; // �۲� �ε� ����
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"ȯ��");
        text1.setCharacterSize(33);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(330.f, 860.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"����.. ���� ����");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"ȯ�� ȣ���� : " + std::to_wstring(heart.getValue()));
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(40.f, 30.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite hwanwoongSprite(hwanwoongTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f);
        RectangleSprite.setPosition(310.f, 850.f);
        PolygonSprite.setPosition(1530.f, 927.f);

        // ��� �̹��� ũ�� ���� (�ʿ��)
        backgroundSprite.setScale(
            window.getSize().x / backgroundTexture.getSize().x,
            window.getSize().y / backgroundTexture.getSize().y
        );

        hwanwoongSprite.setPosition(50.f, 125.f);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // ���콺 Ŭ�� �̺�Ʈ �߰�
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // ���� ȭ������ �Ѿ�� Ŭ�� ���� �߰� (��: PolygonSprite)
                        if (PolygonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            // ���� ȭ������ ��ȯ (��: return 19)
                            return 19;
                        }
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);
            // ��� �׸���
            window.draw(backgroundSprite);
            window.draw(hwanwoongSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3); // ȣ���� �ؽ�Ʈ �׸���
            // ȭ�� ���
            window.display();
        }
        return 0; // �߰��� return 0
    }
};

// ȣ���� �ʱⰪ ���� (�ܺο��� �ʱ�ȭ)
Heart stage1_4_1::heart(50);

#endif // STAGE1_4_1_H

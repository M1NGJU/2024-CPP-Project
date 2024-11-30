#ifndef STAGE1_3_H
#define STAGE1_3_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

class stage1_3_1 {
public:
	static int run(sf::RenderWindow& parentWindow) {
		sf::RenderWindow& window = parentWindow;
		window.setTitle(L"stage1(ȯ��)");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        sf::Texture hwanwoongTexture;
        if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
            return -1;
        }

        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1; // �̹��� �ε� ���� �� ����
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1; // �̹��� �ε� ���� �� ����
        }

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // ����� �۲� ���
            return -1; // �۲� �ε� ���� �� ����
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"ȯ��");
        text1.setCharacterSize(33); // ���� ũ��
        text1.setFillColor(sf::Color::Black); // ���� ����
        text1.setPosition(330.f, 860.f); // �ؽ�Ʈ ��ġ

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"? ������ ���� ����");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite hwanwoongSprite(hwanwoongTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f); // 90% ����, 70% ���η� ���

        // �߾ӿ��� ��¦ �Ʒ��� �̵�
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
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed)
                    window.close();

                // ���콺 Ŭ�� �̺�Ʈ ó��
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        return 15;
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

            // ȭ�� ���
            window.display();
        }

        return 0;

	}
};

#endif
#ifndef HOME3_H
#define HOME3_H

#include <SFML/Graphics.hpp>

class Home3 {
public:
    // home3 ȭ���� ǥ���ϴ� �Լ�
    static int run(sf::RenderWindow& window) {
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
            return -1; // �̹��� �ε� ���� �� ����
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
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // �۲� ��� Ȯ��
            return -1; // �۲� �ε� ���� �� ����
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"���� ���̵�");
        text1.setCharacterSize(33); // ���� ũ��
        text1.setFillColor(sf::Color::Black); // ���� ����
        text1.setPosition(330.f, 860.f); // �ؽ�Ʈ ��ġ

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"?? ��������...????? �ƴ� �� �� �׾����?");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f); // 90% ����, 70% ���η� ���
        RectangleSprite.setPosition(310.f, 850.f);

        PolygonSprite.setPosition(1530.f, 927.f);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1; // ���� �ڵ� ��ȯ
                }

                // ���콺 Ŭ�� ó��
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 0; // Ŭ�� �� 0�� ��ȯ�Ͽ� ���� �������� �Ѿ�ų� ����
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White); // ȭ���� ������� �����

            // ��� �׸���
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            // �ؽ�Ʈ �׸���
            window.draw(text1);
            window.draw(text2);

            // ȭ�� ���
            window.display();
        }

        return -1; // ���� �ڵ� ��ȯ
    }
};

#endif // HOME3_H

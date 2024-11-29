#ifndef HOME3_H
#define HOME3_H

#include <SFML/Graphics.hpp>

class Home3 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Home3");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
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

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f); // 90% ����, 70% ���η� ���
        RectangleSprite.setPosition(310.f, 850.f); // �߾ӿ��� ��¦ �Ʒ��� �̵�
        PolygonSprite.setPosition(1530.f, 927.f);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed)
                    window.close();

                // Ŭ�� �̺�Ʈ ó�� (home4�� ��ȯ)
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // Ŭ���� ��ġ�� Ư�� ������ �ִ��� Ȯ���ϰ�, �׿� �´� �������� ��ȯ
                        if (RectangleSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                            return 8; // Ŭ�� �� Home4 �������� ��ȯ
                        }
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �̹��� �׸���
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};

#endif // HOME3_H
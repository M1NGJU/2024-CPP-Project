#ifndef START_PAGE4_H
#define START_PAGE4_H

#include <SFML/Graphics.hpp>

class StartPage4 { // Ŭ���� �̸��� ���ϸ� ��ġ
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("page4");

        // ��� �ؽ�ó �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/start-page1/medicine.png")) {
            return -1; // �ؽ�ó �ε� ���� �� ����
        }
        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1; // �ؽ�ó �ε� ���� �� ����
        }
        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1; // �ؽ�ó �ε� ���� �� ����
        }

        // ��� ��������Ʈ�� �ؽ�ó ����
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        // �簢�� ũ�� ����
        RectangleSprite.setScale(0.9f, 0.7f); // 90% ����, 70% ���η� ���
        RectangleSprite.setPosition(310.f, 850.f);

        // ������ ��ġ ����
        PolygonSprite.setPosition(1530.f, 927.f);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }

                // ���콺 Ŭ�� ó��
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 5; // ���� ������ ��ȣ �Ǵ� ���� �ڵ� ��ȯ
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �׸���
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            // ȭ�� ���
            window.display();
        }

        return 1; // �⺻ ��ȯ�� (��: ���� ������)
    }
};

#endif // START_PAGE4_H

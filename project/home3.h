#ifndef HOME3_H
#define HOME3_H

#include <SFML/Graphics.hpp>

class Home3 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Home3");

        // ��� �̹��� �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {  // ����� ��� �̹��� ���
            return -1;  // �̹��� �ε� ���� �� ����
        }

        // �ٸ� �ؽ�Ʈ, �̹��� �ε�
        sf::Texture rectangleTexture;
        if (!rectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1;  // �̹��� �ε� ���� �� ����
        }

        sf::Texture polygonTexture;
        if (!polygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1;  // �̹��� �ε� ���� �� ����
        }

        // �ؽ�Ʈ �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {  // �۲� �ε�
            return -1;  // �۲� �ε� ���� �� ����
        }

        // �ؽ�Ʈ ��ü
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

        // ��������Ʈ ����
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite rectangleSprite(rectangleTexture);
        sf::Sprite polygonSprite(polygonTexture);

        rectangleSprite.setScale(0.9f, 0.7f); // 90% ����, 70% ���η� ���
        rectangleSprite.setPosition(310.f, 850.f);
        polygonSprite.setPosition(1530.f, 927.f);

        // Ŭ�� ���� ���� (��: ��� Ŭ�� �� Home4�� �Ѿ���� ����)
        sf::FloatRect clickableArea(500.f, 800.f, 920.f, 240.f); // Ŭ�� ������ ���� (���� ����)

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed)
                    window.close();

                // ���콺 Ŭ�� �̺�Ʈ ó��
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    // ���콺 Ŭ���� Ŭ�� ������ ���� �ȿ� �ִ��� Ȯ��
                    if (clickableArea.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        return 8;  // Home4�� �Ѿ�� ���� ������ ���� 8�� ����
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �׸���
            window.draw(backgroundSprite);
            window.draw(rectangleSprite);
            window.draw(polygonSprite);

            // �ؽ�Ʈ �׸���
            window.draw(text1);
            window.draw(text2);

            // ȭ�� ���
            window.display();
        }

        return 1;  // ������ ����
    }
};

#endif // HOME3_H

#ifndef START_PAGE1_H
#define START_PAGE1_H

#include <SFML/Graphics.hpp>

class StartPage1 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        // ���� â ���
        sf::RenderWindow& window = parentWindow;
        window.setTitle("page1");

        // ��� �ؽ�ó �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/start-page1/background.png")) {
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

        // ���� ���� ��������Ʈ ����
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        // �簢�� ũ�� ���� (���� ũ��� ����)
        RectangleSprite.setScale(0.9f, 0.7f); // 90% ����, 70% ���η� ���
        RectangleSprite.setPosition(310.f, 850.f);

        // ������ ��ġ ����
        PolygonSprite.setPosition(1530.f, 927.f);

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // ����� �۲� ���
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
        text2.setString(L"��... �̷��ٰ� ���ֵ� ���ϰ� �״� �� �ƴϾ�??");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // â �ݱ� �̺�Ʈ ó��
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // ���콺 Ŭ�� �̺�Ʈ ó��
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // ���콺 Ŭ�� ��ǥ ���
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // ������ ��������Ʈ�� �۷ι� �ٿ�� ���
                        sf::FloatRect polygonBounds = PolygonSprite.getGlobalBounds();

                        // ���콺 Ŭ���� ������ ���� �ȿ� �ִ��� Ȯ��
                        if (polygonBounds.contains(mousePos.x, mousePos.y)) {
                            // ���� �������� ��ȯ
                            return 2; // startPage2�� �̵�
                        }
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // �׷��� ��� �׸���
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1); // �ؽ�Ʈ �׸���
            window.draw(text2);

            // ȭ�� ���
            window.display();
        }

        return 1; // �⺻ ��ȯ��
    }
};

#endif // START_PAGE1_H
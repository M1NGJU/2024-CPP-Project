#ifndef HOME2_H
#define HOME2_H

#include <SFML/Graphics.hpp>

class Home2 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Home2");

        // ��� �̹��� �ε�
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

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // ����� �۲� ���
            return -1; // �۲� �ε� ���� �� ����
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"����");
        text1.setCharacterSize(33); // ���� ũ��
        text1.setFillColor(sf::Color::Black); // ���� ����
        text1.setPosition(330.f, 860.f); // �ؽ�Ʈ ��ġ

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"�� �� �Ͼ��???? �����̾� �̳��!!!!!!!!! ��������!!!!!!!!!!!");
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
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // ���콺 Ŭ�� ��ǥ ���
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // ������ ��������Ʈ�� �۷ι� �ٿ�� ���
                        sf::FloatRect polygonBounds = PolygonSprite.getGlobalBounds();

                        // ���콺 Ŭ���� ������ ���� �ȿ� �ִ��� Ȯ��
                        if (polygonBounds.contains(mousePos.x, mousePos.y)) {
                            return 7; 
                        }
                    }
                }
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed)
                    window.close();

            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �׸���
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            window.draw(text1); // �ؽ�Ʈ �׸���
            window.draw(text2);

            // ȭ�� ���
            window.display();
        }

        return 1;
    }
};

#endif // HOME2_H
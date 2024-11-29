#ifndef START_PAGE2_H
#define START_PAGE2_H

#include <SFML/Graphics.hpp>

class StartPage2 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        // ���� â ���
        sf::RenderWindow& window = parentWindow;
        window.setTitle("page2");

        // �ؽ�ó �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/start-page1/background2.png")) {
            return -1; // �̹��� �ε� ���� �� ����
        }

        sf::Texture textTexture;
        if (!textTexture.loadFromFile("imgs/start-page1/text1.png")) {
            return -1; // �̹��� �ε� ���� �� ����
        }

        sf::Texture text2Texture;
        if (!text2Texture.loadFromFile("imgs/start-page1/text2.png")) {
            return -1; // �̹��� �ε� ���� �� ����
        }

        // ��������Ʈ ����
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite textSprite(textTexture);
        sf::Sprite text2Sprite(text2Texture);

        // �ؽ�Ʈ ��������Ʈ ��ġ ����
        textSprite.setPosition(480.f, 500.f); // ù ��° �ؽ�Ʈ ��ġ
        text2Sprite.setPosition(640.f, 650.f); // �� ��° �ؽ�Ʈ ��ġ

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // â �ݱ� �̺�Ʈ ó��
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }

                // ȭ�� Ŭ�� �� ���� �������� �̵�
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 3; // startPage3�� �̵�
                    }
                }
            }

            // ȭ�� �ʱ�ȭ - �� ���
            window.clear(sf::Color::Black);

            // ��������Ʈ �׸���
            window.draw(backgroundSprite); // ���
            window.draw(textSprite);      // ù ��° �ؽ�Ʈ
            window.draw(text2Sprite);     // �� ��° �ؽ�Ʈ

            // ȭ�� ���
            window.display();
        }

        return 1; // �⺻ ���� ��ȯ
    }
};

#endif // START_PAGE2_H
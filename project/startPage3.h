#ifndef START_PAGE3_H
#define START_PAGE3_H

#include <SFML/Graphics.hpp>

class StartPage3 {
public:
        static int run(sf::RenderWindow & parentWindow) {
            sf::RenderWindow& window = parentWindow;
            window.setTitle("page3");

            // �ؽ�ó �ε�
            sf::Texture textTexture;
            if (!textTexture.loadFromFile("imgs/start-page1/text3.png")) {
                return -1;
            }

            sf::Texture text2Texture;
            if (!text2Texture.loadFromFile("imgs/start-page1/text4.png")) {
                return -1;
            }

            sf::Texture text3Texture;
            if (!text3Texture.loadFromFile("imgs/start-page1/text5.png")) {
                return -1;
            }

            // ��������Ʈ ����
            sf::Sprite textSprite(textTexture);
            sf::Sprite text2Sprite(text2Texture);
            sf::Sprite text3Sprite(text3Texture);

            // �ؽ�Ʈ ��������Ʈ ��ġ ����
            textSprite.setPosition(340.f, 350.f);
            text2Sprite.setPosition(740.f, 550.f);
            text3Sprite.setPosition(1040.f, 740.f);

            // ���� ����
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    // �ݱ� ��ư ó��
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        return -1;
                    }

                    // Ŭ�� �̺�Ʈ ó��
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            // ȭ�� Ŭ�� �� startPage4�� �̵�
                            return 4; // startPage4 ����
                        }
                    }
                }

                // ȭ�� �ʱ�ȭ
                window.clear(sf::Color::Black);

                // ��������Ʈ �׸���
                window.draw(textSprite);
                window.draw(text2Sprite);
                window.draw(text3Sprite);

                // ȭ�� ���
                window.display();
            }

            return 3; // �⺻ ���� ��ȯ
    }
};

#endif // START_PAGE3_H

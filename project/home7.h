#ifndef HOME7_H
#define HOME7_H

#include <SFML/Graphics.hpp>

class Home7 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Home7");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
            return -1;
        }

        sf::Texture textTexture;
        if (!textTexture.loadFromFile("imgs/home1/text.png")) {
            return -1;
        }

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite textSprite(textTexture);

        sf::FloatRect textBounds = textSprite.getGlobalBounds();
        float textX = (1920 - textBounds.width) / 2.0f; // ȭ�� �ʺ񿡼� �ؽ�Ʈ �ʺ� �� �� ����
        float textY = (1080 - textBounds.height) / 2.0f; // ȭ�� ���̿��� �ؽ�Ʈ ���̸� �� �� ����
        textSprite.setPosition(textX, textY);

        // ���� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // �ݱ� ��ư ó��
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �̹��� �׸���
            window.draw(backgroundSprite);
            window.draw(textSprite);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};

#endif // HOME7_H

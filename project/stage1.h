#ifndef stage1_H
#define stage1_H

#include <SFML/Graphics.hpp>

class stage1 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("stage1");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // ����� �۲� ���
            std::cout << "Failed to load font" << std::endl; // ����� �޽���
            return -1; // �۲� �ε� ���� �� ����
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"�������� ���� ������");
        text1.setCharacterSize(50); // ���� ũ�� ����
        text1.setFillColor(sf::Color::Black); // ���� ����

        // �ؽ�Ʈ�� ȭ�� �߾ӿ� ��ġ
        sf::FloatRect textBounds = text1.getLocalBounds();
        float textX = (window.getSize().x - textBounds.width) / 2;
        float textY = (window.getSize().y - textBounds.height) / 2;
        text1.setPosition(textX, textY); // �߾� ��ġ ����

        sf::Sprite backgroundSprite(backgroundTexture);

        // ��� �̹��� ũ�� ���� (�ʿ��)
        backgroundSprite.setScale(
            window.getSize().x / backgroundTexture.getSize().x,
            window.getSize().y / backgroundTexture.getSize().y
        );

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

            // ��� �׸���
            window.draw(backgroundSprite);
            window.draw(text1);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};

#endif

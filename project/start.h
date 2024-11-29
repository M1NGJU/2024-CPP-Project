#ifndef START_H
#define START_H

#include <SFML/Graphics.hpp>

class StartPage {
public:
    static int run(sf::RenderWindow& parentWindow) {
        // �� â ��� ���� â ���
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Start");

        // ù ��° �̹��� �ε� (���)
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/start/background1.png")) {
            return -1;  // �̹��� �ε� ���� �� ����
        }

        // �� ��° �̹��� �ε� (Jun)
        sf::Texture junTexture;
        if (!junTexture.loadFromFile("imgs/start/start-jun.png")) {
            return -1;
        }

        // �� ��° �̹��� �ε� (Hwangwoong)
        sf::Texture hwangwoongTexture;
        if (!hwangwoongTexture.loadFromFile("imgs/start/start-hwangwoong.png")) {
            return -1;
        }
        // �� ��° �̹��� �ε� (kangmin)
        sf::Texture kangminTexture;
        if (!kangminTexture.loadFromFile("imgs/start/start-kangmin.png")) {
            return -1;
        }
        // yuki�̹��� �ε�
        sf::Texture yukiTexture;
        if (!yukiTexture.loadFromFile("imgs/start/start-yuki.png")) {
            return -1;
        }
        //���� �ε�
        sf::Texture textTexture;
        if (!textTexture.loadFromFile("imgs/start/startText.png")) {
            return -1;
        }

        sf::Texture text2Textrue;
        if (!text2Textrue.loadFromFile("imgs/start/startText2.png")) {
            return -1;
        }

        // ��������Ʈ ����
        sf::Sprite backgroundSprite(backgroundTexture);   // ��� 
        sf::Sprite junSprite(junTexture);                 // Jun 
        sf::Sprite hwangwoongSprite(hwangwoongTexture);   // Hwangwoong 
        sf::Sprite kangminSprite(kangminTexture); //kangmin
        sf::Sprite yukiSprite(yukiTexture); // yuki
        sf::Sprite textSprite(textTexture); // ����
        sf::Sprite textSprite2(text2Textrue);   //start ����

        // ��� ��������Ʈ�� �Ʒ����� ȭ�� �ϴܿ� ���߱�
        float baseY = 1080; // ȭ�� �ϴ� Y ��ǥ
        float junX = 1920 - junTexture.getSize().x;
        float junY = baseY - junTexture.getSize().y; // ȭ�� �ϴܿ��� Jun �̹��� ���̸�ŭ ����
        junSprite.setPosition(junX, junY);

        float hwangwoongX = 0; // ���� ��
        float hwangwoongY = baseY - hwangwoongTexture.getSize().y; // ȭ�� �ϴܿ��� Hwangwoong ���̸�ŭ ����
        hwangwoongSprite.setPosition(hwangwoongX, hwangwoongY);

        float kangminX = hwangwoongX + hwangwoongTexture.getSize().x - 100; // Hwangwoong ������ ������ 50px ����
        float kangminY = baseY - kangminTexture.getSize().y; // ȭ�� �ϴܿ��� Kangmin ���̸�ŭ ����
        kangminSprite.setPosition(kangminX, kangminY);

        float yukiX = kangminX + kangminTexture.getSize().x + 70; // Kangmin ������ ������ 50px ����
        float yukiY = baseY - yukiTexture.getSize().y;
        yukiSprite.setPosition(yukiX, yukiY);

        float textX = (1920 - textTexture.getSize().x) / 2.3f; // ȭ�� �ʺ��� �߾�
        float textY = (1080 - textTexture.getSize().y) / 2.0f - 150; // ȭ�� ������ �߾ӿ��� 50px ���� �̵�
        textSprite.setPosition(textX, textY);

        float text2X = (1920 - text2Textrue.getSize().x) / 2.0f; // textSprite�� ������ X ��ǥ
        float text2Y = textY + textTexture.getSize().y + 200; // textSprite �Ʒ��� 20px ����
        textSprite2.setPosition(text2X, text2Y);

        // ������ ���¸� ������ ����
        bool changePage = false;

        // ���� ����
        while (window.isOpen() && !changePage) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // ���콺 Ŭ�� �̺�Ʈ �߰�
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // ������ ��ȯ �÷��� ����
                        changePage = true;
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            window.draw(backgroundSprite);
            window.draw(junSprite);
            window.draw(hwangwoongSprite);
            window.draw(kangminSprite);
            window.draw(yukiSprite);
            window.draw(textSprite);
            window.draw(textSprite2);

            // ȭ�� ���
            window.display();
        }

        return changePage ? 1 : 0;
    }
};

#endif // START_H
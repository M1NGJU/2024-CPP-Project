#ifndef STAGE1_7_H
#define STAGE1_7_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

class stage1_7 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1-6(����)");

        // ��� �ؽ�ó �ε�
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/school1.png")) {
            std::cerr << "��� �ؽ�ó �ε� ����!" << std::endl;
            return -1;
        }

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            std::cerr << "��Ʈ �ε� ����!" << std::endl;
            return -1;
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"�п� ���� ��");
        text1.setCharacterSize(100);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(750.f, 500.f);

        sf::Sprite backgroundSprite(backgroundTexture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    return 0;  // â �ݱ�
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �� �ؽ�Ʈ ���
            window.draw(backgroundSprite);
            window.draw(text1);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};


#endif
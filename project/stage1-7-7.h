#ifndef STAGE1_7_7_H
#define STAGE1_7_7_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include "Heart.h"

class stage1_7_7 {
private:
	static Heart heart;

public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle(L"stage1_7_5(��Ű)");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/hackwon1.png")) {
            std::cerr << "Failed to load background image!" << std::endl;
            return -1;
        }

        sf::Texture yukiTexture;
        if (!yukiTexture.loadFromFile("imgs/stage1/yuki1.png")) {
            std::cerr << "Failed to load yuki image!" << std::endl;
            return -1;
        }
        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            std::cout << "�簢�� �̹��� �ε� ����!" << std::endl;
            return -1;
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            std::cout << "�ٰ��� �̹��� �ε� ����!" << std::endl;
            return -1;
        }

        // �۲� �ε�
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {
            std::cout << "�۲� �ε� ����!" << std::endl;
            return -1;
        }

        // �ؽ�Ʈ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"(��������� ���� ���� �����ϴ°ǵ�.. ��)");
        text1.setCharacterSize(33);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(390.f, 900.f);

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"��Ű ȣ���� : " + std::to_wstring(heart.getValue()));
        text2.setCharacterSize(30);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(40.f, 30.f);

        sf::Text text3;
        text3.setFont(font);
        text3.setString(L"��Ű");
        text3.setCharacterSize(33);
        text3.setFillColor(sf::Color::Black);
        text3.setPosition(330.f, 860.f);

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite yukiSprite(yukiTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f);
        RectangleSprite.setPosition(310.f, 850.f);
        PolygonSprite.setPosition(1530.f, 927.f);

        yukiSprite.setPosition(3.f, 1.f);

        //while
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ��� �� ��������Ʈ �׸���
            window.draw(backgroundSprite);
            window.draw(yukiSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);

            // ȭ�� ���
            window.display();
        }

        return 0;
    }
};
Heart stage1_7_7::heart(40);
#endif
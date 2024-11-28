#include <SFML/Graphics.hpp>

int main() {
    // ������ ���� (800x600 ũ��, ����: "SFML ������")
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "page3");

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

    sf::Sprite textSprite(textTexture);
    sf::Sprite text2Sprite(text2Texture);
    sf::Sprite text3Sprite(text3Texture);

    textSprite.setPosition(340.f, 350.f);
    text2Sprite.setPosition(740.f, 550.f);
    text3Sprite.setPosition(1040.f, 740.f);

    // ���� ����
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // �ݱ� ��ư ó��
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ȭ�� �ʱ�ȭ
        window.clear(sf::Color::Black);

        window.draw(textSprite);
        window.draw(text2Sprite);
        window.draw(text3Sprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

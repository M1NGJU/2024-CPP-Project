#include <SFML/Graphics.hpp>

int main() {
    // ������ ���� (800x600 ũ��, ����: "SFML ������")
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "page2");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/start-page1/background2.png")) {
        return -1; // �̹��� �ε� ���� �� ����
    }

    sf::Texture textTexture;
    if (!textTexture.loadFromFile("imgs/start-page1/text1.png")) {
        return -1;
    }

    sf::Texture text2Texture;
    if (!text2Texture.loadFromFile("imgs/start-page1/text2.png")) {
        return -1;
    }



    sf::Sprite backgroundSprite(backgroundTexture);
    sf::Sprite textSprite(textTexture);
    sf::Sprite text2Sprite(text2Texture);

    textSprite.setPosition(480.f, 500.f);
    text2Sprite.setPosition(640.f, 650.f);

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

        window.draw(backgroundSprite);
        window.draw(textSprite);
        window.draw(text2Sprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

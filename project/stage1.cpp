#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // ������ ���� (1920x1080 ũ��, ����: "SFML ������")
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "stage1");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
        std::cerr << "�̹��� �ε� ����!" << std::endl;
        return -1;
    }

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

        // ȭ�� ���
        window.display();
    }

    return 0;
}

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

    sf::Texture hwanwoongTexture;
    if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);
    sf::Sprite hwanwoongSprite(hwanwoongTexture);

    // ��� �̹��� ũ�� ���� (�ʿ��)
    backgroundSprite.setScale(
        window.getSize().x / backgroundTexture.getSize().x,
        window.getSize().y / backgroundTexture.getSize().y
    );

    hwanwoongSprite.setPosition(50.f, 125.f);

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
        window.draw(hwanwoongSprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

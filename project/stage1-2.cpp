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

    sf::Texture RectangleTexture;
    if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
        return -1; // �̹��� �ε� ���� �� ����
    }

    sf::Texture PolygonTexture;
    if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
        return -1; // �̹��� �ε� ���� �� ����
    }

    sf::Sprite backgroundSprite(backgroundTexture);
    sf::Sprite hwanwoongSprite(hwanwoongTexture);
    sf::Sprite RectangleSprite(RectangleTexture);
    sf::Sprite PolygonSprite(PolygonTexture);

    RectangleSprite.setScale(0.9f, 0.7f); // 90% ����, 70% ���η� ���

    // �߾ӿ��� ��¦ �Ʒ��� �̵�
    RectangleSprite.setPosition(310.f, 850.f);

    PolygonSprite.setPosition(1530.f, 927.f);

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
        window.draw(RectangleSprite);
        window.draw(PolygonSprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

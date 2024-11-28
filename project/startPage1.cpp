#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "page1");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/start-page1/background.png")) {
        return -1; // �̹��� �ε� ���� �� ����
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
    sf::Sprite RectangleSprite(RectangleTexture);
    sf::Sprite PolygonSprite(PolygonTexture);

    // �簢�� ũ�� ���� (���� ũ��� ����)
    RectangleSprite.setScale(0.9f, 0.7f); // 90% ����, 70% ���η� ���

    // �߾ӿ��� ��¦ �Ʒ��� �̵�
    RectangleSprite.setPosition(310.f, 850.f);

    // �������� ������ ��ġ (1637, 927)�� �̵�
    PolygonSprite.setPosition(1530.f, 927.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // â �ݱ� �̺�Ʈ ó��
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // ȭ�� �ʱ�ȭ
        window.clear(sf::Color::White);

        // ��� �׸���
        window.draw(backgroundSprite);
        window.draw(RectangleSprite);
        window.draw(PolygonSprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

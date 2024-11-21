#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");

    // �̹��� �ε�
    sf::Texture background; // sf::Texture�� ����
    if (!background.loadFromFile("imgs/background1.png")) {
        return -1;  // �̹��� �ε� ���� �� ����
    }

    // ��������Ʈ ����
    sf::Sprite sprite(background);

    // ���� ����
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // �ݱ� ��ư ó��
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ȭ�� �ʱ�ȭ (������ �Ͼ��)
        window.clear(sf::Color::White);

        // �̹��� ���
        window.draw(sprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

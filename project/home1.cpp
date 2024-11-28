#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "home");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

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

        // ��� �̹��� �׸���
        window.draw(backgroundSprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

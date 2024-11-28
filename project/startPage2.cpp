#include <SFML/Graphics.hpp>

int main() {
    // ������ ���� (800x600 ũ��, ����: "SFML ������")
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "page2");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/start-page1/background2.png")) {
        return -1; // �̹��� �ε� ���� �� ����
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
        window.clear(sf::Color::Black);

        window.draw(backgroundSprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

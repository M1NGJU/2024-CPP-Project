#include <SFML/Graphics.hpp>

int main() {
    // ������ ���� (800x600 ũ��, ����: "SFML ������")
    sf::RenderWindow window(sf::VideoMode(1440, 1024), "SFML");

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

        // ȭ�� ���
        window.display();
    }

    return 0;
}

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "home5");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
        return -1;
    }

    sf::Texture textTexture;
    if (!textTexture.loadFromFile("imgs/home1/homeText.png")) {
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);
    sf::Sprite textSprite(textTexture);

    // ���� �̹��� ũ�� ���̱� (80%�� ���)
    textSprite.setScale(0.8f, 0.8f);

    // ���� �̹��� �߾� ����
    sf::FloatRect textBounds = textSprite.getGlobalBounds();
    float textX = (1920 - textBounds.width) / 2.0f; // ȭ�� �ʺ񿡼� �ؽ�Ʈ �ʺ� �� �� ����
    float textY = (1080 - textBounds.height) / 2.0f; // ȭ�� ���̿��� �ؽ�Ʈ ���̸� �� �� ����
    textSprite.setPosition(textX, textY);

    // ���� ����
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // ��� �̹��� �� �ؽ�Ʈ ���
        window.draw(backgroundSprite);
        window.draw(textSprite);

        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");

    // ù ��° �̹��� �ε� (���)
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/start/background1.png")) {
        return -1;  // �̹��� �ε� ���� �� ����
    }

    // �� ��° �̹��� �ε� (Jun)
    sf::Texture junTexture;
    if (!junTexture.loadFromFile("imgs/start/start-jun.png")) {
        return -1;
    }

    // �� ��° �̹��� �ε� (Hwangwoong)
    sf::Texture hwangwoongTexture;
    if (!hwangwoongTexture.loadFromFile("imgs/start/start-hwangwoong.png")) {
        return -1;
    }
    // �� ��° �̹��� �ε� (kangmin)
    sf::Texture kangminTexture;
    if (!kangminTexture.loadFromFile("imgs/start/start-kangmin.png")) {
        return -1;
    }
    // yuki�̹��� �ε�
    sf::Texture yukiTexture;
    if (!yukiTexture.loadFromFile("imgs/start/start-yuki.png")) {
        return -1;
    }

    // ��������Ʈ ����
    sf::Sprite backgroundSprite(backgroundTexture);   // ��� 
    sf::Sprite junSprite(junTexture);                 // Jun 
    sf::Sprite hwangwoongSprite(hwangwoongTexture);   // Hwangwoong 
    sf::Sprite kangminSprite(kangminTexture); //kangmin
    sf::Sprite yukiSprite(yukiTexture); // yuki

    // ��� ��������Ʈ�� �Ʒ����� ȭ�� �ϴܿ� ���߱�
    float baseY = 1080; // ȭ�� �ϴ� Y ��ǥ
    float junX = 1920 - junTexture.getSize().x; 
    float junY = baseY - junTexture.getSize().y; // ȭ�� �ϴܿ��� Jun �̹��� ���̸�ŭ ����
    junSprite.setPosition(junX, junY);

    float hwangwoongX = 0; // ���� ��
    float hwangwoongY = baseY - hwangwoongTexture.getSize().y; // ȭ�� �ϴܿ��� Hwangwoong ���̸�ŭ ����
    hwangwoongSprite.setPosition(hwangwoongX, hwangwoongY);

    float kangminX = hwangwoongX + hwangwoongTexture.getSize().x-100; // Hwangwoong ������ ������ 50px ����
    float kangminY = baseY - kangminTexture.getSize().y; // ȭ�� �ϴܿ��� Kangmin ���̸�ŭ ����
    kangminSprite.setPosition(kangminX, kangminY);

    float yukiX = kangminX + kangminTexture.getSize().x + 70; // Kangmin ������ ������ 50px ����
    float yukiY = baseY - yukiTexture.getSize().y;
    yukiSprite.setPosition(yukiX, yukiY);





    // ���� ����
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ȭ�� �ʱ�ȭ
        window.clear(sf::Color::White);

        window.draw(backgroundSprite);
        window.draw(junSprite);
        window.draw(hwangwoongSprite);
        window.draw(kangminSprite);
        window.draw(yukiSprite);

        // ȭ�� ���
        window.display();
    }

    return 0;
}

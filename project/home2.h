class Home2 {
public:
    static int run(sf::RenderWindow& window) {
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
            return -1; // ���� �� ����
        }

        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1; // ���� �� ����
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1; // ���� �� ����
        }

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f);
        RectangleSprite.setPosition(310.f, 850.f);

        PolygonSprite.setPosition(1530.f, 927.f);

        // ���� ���� (ȭ�� ���� �� �̺�Ʈ ó��)
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }

                // ���콺 Ŭ�� ó��
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 7; // Ŭ�� �� home3���� �Ѿ��
                    }
                }
            }

            // ȭ�� �ʱ�ȭ
            window.clear(sf::Color::White);

            // ���� ��������Ʈ �׸���
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            // ȭ�� ���
            window.display();
        }

        return 1; // �⺻ ��ȯ�� (��: ���� ������)
    }
};
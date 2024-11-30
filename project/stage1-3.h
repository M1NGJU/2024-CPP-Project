#ifndef stage1_3_H
#define stage1_3_H

#include <SFML/Graphics.hpp>

class stage1_3 {
public:
	static int run(sf::RenderWindow& parentWindow) {
		sf::RenderWindow& window = parentWindow;
		window.setTitle(L"stage1(ȯ��)");

		sf::Texture backgroundTexture;
		if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
			return -1;
		}

		sf::Texture hwanwoongTexture;
		if (!hwanwoongTexture.loadFromFile("imgs/stage1/hwanwoong1.png")) {
			return -1;
		}

		sf::Texture RectangleTexture;
		if (!RectangleTexture.loadFromFile("imgs/stage1/RectanglePink.png")) {
			return -1; // �̹��� �ε� ���� �� ����
		}

		sf::Texture RectangleTexture2;
		if (!RectangleTexture2.loadFromFile("imgs/stage1/RectanglePink.png")) {
			return -1; // �̹��� �ε� ���� �� ����
		}

		sf::Sprite backgroundSprite(backgroundTexture);
		sf::Sprite hwanwoongSprite(hwanwoongTexture);
		sf::Sprite RectangleSprite(RectangleTexture);
		sf::Sprite RectangleSprite2(RectangleTexture2);

		hwanwoongSprite.setPosition(50.f, 125.f);
		RectangleSprite.setPosition(870.f, 350.f);
		RectangleSprite2.setPosition(870.f, 550.f);

		RectangleSprite.setScale(0.8f, 0.9f); 
		RectangleSprite2.setScale(0.8f, 0.9f); 

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
			window.draw(RectangleSprite2);

			window.display();
		}
		return 0;
	}
};

#endif
#ifndef LASTPAGE_H
#define LASTPAGE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

class LastPage {
public:
	static int run(sf::RenderWindow& parentWindow) {
		sf::RenderWindow& window = parentWindow;
		window.setTitle(L"last");
		sf::Texture backgroundTexture;
		if (!backgroundTexture.loadFromFile("imgs/start/background1.png")) {
			std::cerr << "Failed to load background image!" << std::endl;
			return -1;
		}

		sf::Font font;
		if (!font.loadFromFile("font/Jua-Regular.ttf")) {
			return -1;
		}

		sf::Text text1;
		text1.setFont(font);
		text1.setString(L"�ູ�� ���� �ϼ̳���??");
		text1.setCharacterSize(70);
		text1.setFillColor(sf::Color::Black);
		text1.setPosition(570.f, 500.f);

		sf::Text text2;
		text2.setFont(font);
		text2.setString(L"���������� ����� ȣ������ �ø� ����� ���ָ� �ϸ� �˴ϴ�!!");
		text2.setCharacterSize(70);
		text2.setFillColor(sf::Color::Black);
		text2.setPosition(100.f, 700.f);

		sf::Sprite backgroundSprite(backgroundTexture);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					return -1;
				}
			}

			// ȭ�� �ʱ�ȭ
			window.clear(sf::Color::White);

			// ��� �� ��������Ʈ �׸���
			window.draw(backgroundSprite);
			window.draw(text1);
			window.draw(text2);

			// ȭ�� ���
			window.display();
		}

		return 0;

	}
};

#endif
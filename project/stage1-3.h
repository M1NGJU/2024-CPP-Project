#ifndef stage1_3_H
#define stage1_3_H

#include <SFML/Graphics.hpp>

class stage1_3 {
public:
	static int run(sf::RenderWindow& parentWindow) {
		sf::RenderWindow& window = parentWindow;
		window.setTitle(L"stage1(환웅)");

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
			return -1; // 이미지 로드 실패 시 종료
		}

		sf::Texture RectangleTexture2;
		if (!RectangleTexture2.loadFromFile("imgs/stage1/RectanglePink.png")) {
			return -1; // 이미지 로드 실패 시 종료
		}

		// 글꼴 로드
		sf::Font font;
		if (!font.loadFromFile("font/Jua-Regular.ttf")) { // 사용할 글꼴 경로
			return -1; // 글꼴 로드 실패 시 종료
		}

		// 텍스트 생성
		sf::Text text1;
		text1.setFont(font);
		text1.setString(L"미안... 늦었지 빨리 가자");
		text1.setCharacterSize(40); // 글자 크기
		text1.setFillColor(sf::Color::Black); // 글자 색상
		text1.setPosition(1080.f, 400.f); // 텍스트 위치

		sf::Text text2;
		text2.setFont(font);
		text2.setString(L"ㅋㅋㅋ새학기 지각 가보자고~");
		text2.setCharacterSize(40);
		text2.setFillColor(sf::Color::Black);
		text2.setPosition(1050.f, 600.f);

		sf::Text text3;
		text3.setFont(font);
		text3.setString(L"환웅 호감도 : 50");
		text3.setCharacterSize(30);
		text3.setFillColor(sf::Color::Black);
		text3.setPosition(40.f, 30.f);

		sf::Sprite backgroundSprite(backgroundTexture);
		sf::Sprite hwanwoongSprite(hwanwoongTexture);
		sf::Sprite RectangleSprite(RectangleTexture);
		sf::Sprite RectangleSprite2(RectangleTexture2);

		hwanwoongSprite.setPosition(50.f, 125.f);
		RectangleSprite.setPosition(870.f, 350.f);
		RectangleSprite2.setPosition(870.f, 550.f);

		RectangleSprite.setScale(0.8f, 0.9f); 
		RectangleSprite2.setScale(0.8f, 0.9f); 

		// 메인 루프
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				// 닫기 버튼 처리
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// 화면 초기화
			window.clear(sf::Color::White);

			// 배경 그리기
			window.draw(backgroundSprite);
			window.draw(hwanwoongSprite);
			window.draw(RectangleSprite);
			window.draw(RectangleSprite2);

			window.draw(text1);
			window.draw(text2);
			window.draw(text3);

			window.display();
		}
		return 0;
	}
};

#endif
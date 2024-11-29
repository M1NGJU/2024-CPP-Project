#ifndef HOME5_H
#define HOME5_H

#include <SFML/Graphics.hpp>

class Home5 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Home5");

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

        // 글자 이미지 크기 줄이기 (80%로 축소)
        textSprite.setScale(0.8f, 0.8f);

        // 글자 이미지 중앙 정렬
        sf::FloatRect textBounds = textSprite.getGlobalBounds();
        float textX = (1920 - textBounds.width) / 2.0f; // 화면 너비에서 텍스트 너비를 뺀 후 절반
        float textY = (1080 - textBounds.height) / 2.0f; // 화면 높이에서 텍스트 높이를 뺀 후 절반
        textSprite.setPosition(textX, textY);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);

            // 배경 이미지 및 텍스트 출력
            window.draw(backgroundSprite);
            window.draw(textSprite);

            window.display();
        }

        return 0;
    }
};

#endif // HOME5_H

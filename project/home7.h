#ifndef HOME7_H
#define HOME7_H

#include <SFML/Graphics.hpp>

class Home7 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Home7");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
            return -1;
        }

        sf::Texture textTexture;
        if (!textTexture.loadFromFile("imgs/home1/text.png")) {
            return -1;
        }

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite textSprite(textTexture);

        sf::FloatRect textBounds = textSprite.getGlobalBounds();
        float textX = (1920 - textBounds.width) / 2.0f; // 화면 너비에서 텍스트 너비를 뺀 후 절반
        float textY = (1080 - textBounds.height) / 2.0f; // 화면 높이에서 텍스트 높이를 뺀 후 절반
        textSprite.setPosition(textX, textY);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed)
                    window.close();

                // 마우스 클릭 이벤트 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                            std::cout << "Mouse clicked on PolygonSprite, transitioning to Home7" << std::endl; // 디버그 메시지
                            return 12;
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 이미지 그리기
            window.draw(backgroundSprite);
            window.draw(textSprite);

            // 화면 출력
            window.display();
        }

        return 0;
    }
};

#endif // HOME7_H

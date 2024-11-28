#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "home7");

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

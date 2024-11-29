#include <SFML/Graphics.hpp>
#include <iostream>

// 현재 화면 상태를 나타내는 열거형
enum start {
    START_SCREEN,
    PAGE1_SCREEN
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "main.cpp");

    // 시작 화면 (start.cpp)
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/start/background1.png")) {
        return -1; // 이미지 로드 실패 시 종료
    }
    sf::Texture junTexture;
    if (!junTexture.loadFromFile("imgs/start/start-jun.png")) {
        return -1;
    }
    sf::Texture hwangwoongTexture;
    if (!hwangwoongTexture.loadFromFile("imgs/start/start-hwangwoong.png")) {
        return -1;
    }
    sf::Texture kangminTexture;
    if (!kangminTexture.loadFromFile("imgs/start/start-kangmin.png")) {
        return -1;
    }
    sf::Texture yukiTexture;
    if (!yukiTexture.loadFromFile("imgs/start/start-yuki.png")) {
        return -1;
    }
    sf::Texture textTexture;
    if (!textTexture.loadFromFile("imgs/start/startText.png")) {
        return -1;
    }
    sf::Texture text2Texture;
    if (!text2Texture.loadFromFile("imgs/start/startText2.png")) {
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);
    sf::Sprite junSprite(junTexture);
    sf::Sprite hwangwoongSprite(hwangwoongTexture);
    sf::Sprite kangminSprite(kangminTexture);
    sf::Sprite yukiSprite(yukiTexture);
    sf::Sprite textSprite(textTexture);
    sf::Sprite textSprite2(text2Texture);

    float baseY = 1080;
    junSprite.setPosition(1920 - junTexture.getSize().x, baseY - junTexture.getSize().y);
    hwangwoongSprite.setPosition(0, baseY - hwangwoongTexture.getSize().y);
    kangminSprite.setPosition(hwangwoongTexture.getSize().x - 100, baseY - kangminTexture.getSize().y);
    yukiSprite.setPosition(kangminSprite.getPosition().x + kangminTexture.getSize().x + 70, baseY - yukiTexture.getSize().y);
    textSprite.setPosition((1920 - textTexture.getSize().x) / 2.3f, (1080 - textTexture.getSize().y) / 2.0f - 150);
    textSprite2.setPosition((1920 - text2Texture.getSize().x) / 2.0f, textSprite.getPosition().y + textTexture.getSize().y + 200);

    // 페이지1 화면 (startPage1.cpp)
    sf::Texture page1BackgroundTexture;
    if (!page1BackgroundTexture.loadFromFile("imgs/start-page1/background.png")) {
        return -1;
    }
    sf::Texture rectangleTexture;
    if (!rectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
        return -1;
    }
    sf::Texture polygonTexture;
    if (!polygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
        return -1;
    }
    sf::Font font;
    if (!font.loadFromFile("font/gulim.ttc")) {
        return -1;
    }

    sf::Sprite page1BackgroundSprite(page1BackgroundTexture);
    sf::Sprite rectangleSprite(rectangleTexture);
    sf::Sprite polygonSprite(polygonTexture);
    rectangleSprite.setScale(0.9f, 0.7f);
    rectangleSprite.setPosition(310.f, 850.f);
    polygonSprite.setPosition(1530.f, 927.f);

    sf::Text page1Text("정민레이디", font, 100);
    page1Text.setFillColor(sf::Color::Black);
    page1Text.setStyle(sf::Text::Bold);
    page1Text.setPosition(1920 / 2.f - page1Text.getGlobalBounds().width / 2.f, 200.f);

    // 현재 화면 상태를 저장
    start currentScreen = START_SCREEN;

    // 메인 루프
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // 마우스 클릭 이벤트로 화면 전환
            if (event.type == sf::Event::MouseButtonPressed && currentScreen == START_SCREEN) {
                currentScreen = PAGE1_SCREEN; // 화면 전환
            }
        }

        // 화면 렌더링
        window.clear(sf::Color::White);

        if (currentScreen == START_SCREEN) {
            window.draw(backgroundSprite);
            window.draw(junSprite);
            window.draw(hwangwoongSprite);
            window.draw(kangminSprite);
            window.draw(yukiSprite);
            window.draw(textSprite);
            window.draw(textSprite2);
        }
        else if (currentScreen == PAGE1_SCREEN) {
            window.draw(page1BackgroundSprite);
            window.draw(rectangleSprite);
            window.draw(polygonSprite);
            window.draw(page1Text);
        }

        window.display();
    }

    return 0;
}

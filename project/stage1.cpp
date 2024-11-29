#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 윈도우 생성 (1920x1080 크기, 제목: "SFML 윈도우")
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "stage1");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
        std::cerr << "이미지 로드 실패!" << std::endl;
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    // 배경 이미지 크기 조정 (필요시)
    backgroundSprite.setScale(
        window.getSize().x / backgroundTexture.getSize().x,
        window.getSize().y / backgroundTexture.getSize().y
    );

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

        // 화면 출력
        window.display();
    }

    return 0;
}

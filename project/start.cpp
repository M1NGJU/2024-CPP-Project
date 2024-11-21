#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");

    // 이미지 로드
    sf::Texture background; // sf::Texture로 변경
    if (!background.loadFromFile("imgs/background1.png")) {
        return -1;  // 이미지 로드 실패 시 종료
    }

    // 스프라이트 생성
    sf::Sprite sprite(background);

    // 메인 루프
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // 닫기 버튼 처리
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 화면 초기화 (배경색은 하얀색)
        window.clear(sf::Color::White);

        // 이미지 출력
        window.draw(sprite);

        // 화면 출력
        window.display();
    }

    return 0;
}

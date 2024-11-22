#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");

    // 첫 번째 이미지 로드 (배경)
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("imgs/start/background1.png")) {
        return -1;  // 이미지 로드 실패 시 종료
    }

    // 두 번째 이미지 로드 (Jun)
    sf::Texture junTexture;
    if (!junTexture.loadFromFile("imgs/start/start-jun.png")) {
        return -1;
    }

    // 세 번째 이미지 로드 (Hwangwoong)
    sf::Texture hwangwoongTexture;
    if (!hwangwoongTexture.loadFromFile("imgs/start/start-hwangwoong.png")) {
        return -1;
    }
    // 네 번째 이미지 로드 (kangmin)
    sf::Texture kangminTexture;
    if (!kangminTexture.loadFromFile("imgs/start/start-kangmin.png")) {
        return -1;
    }
    // yuki이미지 로드
    sf::Texture yukiTexture;
    if (!yukiTexture.loadFromFile("imgs/start/start-yuki.png")) {
        return -1;
    }

    // 스프라이트 생성
    sf::Sprite backgroundSprite(backgroundTexture);   // 배경 
    sf::Sprite junSprite(junTexture);                 // Jun 
    sf::Sprite hwangwoongSprite(hwangwoongTexture);   // Hwangwoong 
    sf::Sprite kangminSprite(kangminTexture); //kangmin
    sf::Sprite yukiSprite(yukiTexture); // yuki

    // 모든 스프라이트의 아래쪽을 화면 하단에 맞추기
    float baseY = 1080; // 화면 하단 Y 좌표
    float junX = 1920 - junTexture.getSize().x; 
    float junY = baseY - junTexture.getSize().y; // 화면 하단에서 Jun 이미지 높이만큼 위로
    junSprite.setPosition(junX, junY);

    float hwangwoongX = 0; // 왼쪽 끝
    float hwangwoongY = baseY - hwangwoongTexture.getSize().y; // 화면 하단에서 Hwangwoong 높이만큼 위로
    hwangwoongSprite.setPosition(hwangwoongX, hwangwoongY);

    float kangminX = hwangwoongX + hwangwoongTexture.getSize().x-100; // Hwangwoong 오른쪽 끝에서 50px 간격
    float kangminY = baseY - kangminTexture.getSize().y; // 화면 하단에서 Kangmin 높이만큼 위로
    kangminSprite.setPosition(kangminX, kangminY);

    float yukiX = kangminX + kangminTexture.getSize().x + 70; // Kangmin 오른쪽 끝에서 50px 간격
    float yukiY = baseY - yukiTexture.getSize().y;
    yukiSprite.setPosition(yukiX, yukiY);





    // 메인 루프
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 화면 초기화
        window.clear(sf::Color::White);

        window.draw(backgroundSprite);
        window.draw(junSprite);
        window.draw(hwangwoongSprite);
        window.draw(kangminSprite);
        window.draw(yukiSprite);

        // 화면 출력
        window.display();
    }

    return 0;
}

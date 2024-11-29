#ifndef START_H
#define START_H

#include <SFML/Graphics.hpp>

class StartPage {
public:
    static int run(sf::RenderWindow& parentWindow) {
        // 새 창 대신 기존 창 사용
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Start");

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
        //글자 로드
        sf::Texture textTexture;
        if (!textTexture.loadFromFile("imgs/start/startText.png")) {
            return -1;
        }

        sf::Texture text2Textrue;
        if (!text2Textrue.loadFromFile("imgs/start/startText2.png")) {
            return -1;
        }

        // 스프라이트 생성
        sf::Sprite backgroundSprite(backgroundTexture);   // 배경 
        sf::Sprite junSprite(junTexture);                 // Jun 
        sf::Sprite hwangwoongSprite(hwangwoongTexture);   // Hwangwoong 
        sf::Sprite kangminSprite(kangminTexture); //kangmin
        sf::Sprite yukiSprite(yukiTexture); // yuki
        sf::Sprite textSprite(textTexture); // 글자
        sf::Sprite textSprite2(text2Textrue);   //start 글자

        // 모든 스프라이트의 아래쪽을 화면 하단에 맞추기
        float baseY = 1080; // 화면 하단 Y 좌표
        float junX = 1920 - junTexture.getSize().x;
        float junY = baseY - junTexture.getSize().y; // 화면 하단에서 Jun 이미지 높이만큼 위로
        junSprite.setPosition(junX, junY);

        float hwangwoongX = 0; // 왼쪽 끝
        float hwangwoongY = baseY - hwangwoongTexture.getSize().y; // 화면 하단에서 Hwangwoong 높이만큼 위로
        hwangwoongSprite.setPosition(hwangwoongX, hwangwoongY);

        float kangminX = hwangwoongX + hwangwoongTexture.getSize().x - 100; // Hwangwoong 오른쪽 끝에서 50px 간격
        float kangminY = baseY - kangminTexture.getSize().y; // 화면 하단에서 Kangmin 높이만큼 위로
        kangminSprite.setPosition(kangminX, kangminY);

        float yukiX = kangminX + kangminTexture.getSize().x + 70; // Kangmin 오른쪽 끝에서 50px 간격
        float yukiY = baseY - yukiTexture.getSize().y;
        yukiSprite.setPosition(yukiX, yukiY);

        float textX = (1920 - textTexture.getSize().x) / 2.3f; // 화면 너비의 중앙
        float textY = (1080 - textTexture.getSize().y) / 2.0f - 150; // 화면 높이의 중앙에서 50px 위로 이동
        textSprite.setPosition(textX, textY);

        float text2X = (1920 - text2Textrue.getSize().x) / 2.0f; // textSprite와 동일한 X 좌표
        float text2Y = textY + textTexture.getSize().y + 200; // textSprite 아래로 20px 간격
        textSprite2.setPosition(text2X, text2Y);

        // 페이지 상태를 추적할 변수
        bool changePage = false;

        // 메인 루프
        while (window.isOpen() && !changePage) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // 마우스 클릭 이벤트 추가
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 페이지 전환 플래그 설정
                        changePage = true;
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            window.draw(backgroundSprite);
            window.draw(junSprite);
            window.draw(hwangwoongSprite);
            window.draw(kangminSprite);
            window.draw(yukiSprite);
            window.draw(textSprite);
            window.draw(textSprite2);

            // 화면 출력
            window.display();
        }

        return changePage ? 1 : 0;
    }
};

#endif // START_H
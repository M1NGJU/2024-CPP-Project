#ifndef HOME3_H
#define HOME3_H

#include <SFML/Graphics.hpp>

class Home3 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("Home3");

        // 배경 이미지 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {  // 변경된 배경 이미지 경로
            return -1;  // 이미지 로드 실패 시 종료
        }

        // 다른 텍스트, 이미지 로드
        sf::Texture rectangleTexture;
        if (!rectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1;  // 이미지 로드 실패 시 종료
        }

        sf::Texture polygonTexture;
        if (!polygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1;  // 이미지 로드 실패 시 종료
        }

        // 텍스트 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) {  // 글꼴 로드
            return -1;  // 글꼴 로드 실패 시 종료
        }

        // 텍스트 객체
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"정민 레이디");
        text1.setCharacterSize(33); // 글자 크기
        text1.setFillColor(sf::Color::Black); // 글자 색상
        text1.setPosition(330.f, 860.f); // 텍스트 위치

        sf::Text text2;
        text2.setFont(font);
        text2.setString(L"?? 누구세요...????? 아니 저 안 죽었어요?");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        // 스프라이트 설정
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite rectangleSprite(rectangleTexture);
        sf::Sprite polygonSprite(polygonTexture);

        rectangleSprite.setScale(0.9f, 0.7f); // 90% 가로, 70% 세로로 축소
        rectangleSprite.setPosition(310.f, 850.f);
        polygonSprite.setPosition(1530.f, 927.f);

        // 클릭 영역 설정 (예: 배경 클릭 시 Home4로 넘어가도록 설정)
        sf::FloatRect clickableArea(500.f, 800.f, 920.f, 240.f); // 클릭 가능한 영역 (변경 가능)

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed)
                    window.close();

                // 마우스 클릭 이벤트 처리
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    // 마우스 클릭이 클릭 가능한 영역 안에 있는지 확인
                    if (clickableArea.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        return 8;  // Home4로 넘어가기 위해 페이지 상태 8로 설정
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(rectangleSprite);
            window.draw(polygonSprite);

            // 텍스트 그리기
            window.draw(text1);
            window.draw(text2);

            // 화면 출력
            window.display();
        }

        return 1;  // 페이지 유지
    }
};

#endif // HOME3_H

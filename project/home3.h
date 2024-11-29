#ifndef HOME3_H
#define HOME3_H

#include <SFML/Graphics.hpp>

class Home3 {
public:
    // home3 화면을 표시하는 함수
    static int run(sf::RenderWindow& window) {
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/home1/home.png")) {
            return -1; // 이미지 로드 실패 시 종료
        }

        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1; // 이미지 로드 실패 시 종료
        }

        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1; // 이미지 로드 실패 시 종료
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // 글꼴 경로 확인
            return -1; // 글꼴 로드 실패 시 종료
        }

        // 텍스트 생성
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

        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        RectangleSprite.setScale(0.9f, 0.7f); // 90% 가로, 70% 세로로 축소
        RectangleSprite.setPosition(310.f, 850.f);

        PolygonSprite.setPosition(1530.f, 927.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1; // 종료 코드 반환
                }

                // 마우스 클릭 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 0; // 클릭 시 0을 반환하여 다음 페이지로 넘어가거나 종료
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White); // 화면을 흰색으로 지우기

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            // 텍스트 그리기
            window.draw(text1);
            window.draw(text2);

            // 화면 출력
            window.display();
        }

        return -1; // 종료 코드 반환
    }
};

#endif // HOME3_H

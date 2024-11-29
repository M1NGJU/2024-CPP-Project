#ifndef START_PAGE1_H
#define START_PAGE1_H

#include <SFML/Graphics.hpp>

class StartPage1 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        // 기존 창 사용
        sf::RenderWindow& window = parentWindow;
        window.setTitle("page1");

        // 배경 텍스처 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/start-page1/background.png")) {
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

        // 배경과 도형 스프라이트 생성
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        // 사각형 크기 조정 (절반 크기로 설정)
        RectangleSprite.setScale(0.9f, 0.7f); // 90% 가로, 70% 세로로 축소
        RectangleSprite.setPosition(310.f, 850.f);

        // 폴리곤 위치 설정
        PolygonSprite.setPosition(1530.f, 927.f);

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // 사용할 글꼴 경로
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
        text2.setString(L"하... 이러다가 연애도 못하고 죽는 거 아니야??");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 창 닫기 이벤트 처리
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // 마우스 클릭 이벤트 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 마우스 클릭 좌표 얻기
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // 폴리곤 스프라이트의 글로벌 바운드 얻기
                        sf::FloatRect polygonBounds = PolygonSprite.getGlobalBounds();

                        // 마우스 클릭이 폴리곤 영역 안에 있는지 확인
                        if (polygonBounds.contains(mousePos.x, mousePos.y)) {
                            // 다음 페이지로 전환
                            return 2; // startPage2로 이동
                        }
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 그래픽 요소 그리기
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1); // 텍스트 그리기
            window.draw(text2);

            // 화면 출력
            window.display();
        }

        return 1; // 기본 반환값
    }
};

#endif // START_PAGE1_H
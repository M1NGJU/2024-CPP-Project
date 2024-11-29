
#ifndef START_PAGE4_H
#define START_PAGE4_H
#include <SFML/Graphics.hpp>

class StartPage4 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("page4");

        // 배경 텍스처 로드
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/start-page1/medicine.png")) {
            return -1; // 텍스처 로드 실패 시 종료
        }
        sf::Texture RectangleTexture;
        if (!RectangleTexture.loadFromFile("imgs/start-page1/Rectangle.png")) {
            return -1; // 텍스처 로드 실패 시 종료
        }
        sf::Texture PolygonTexture;
        if (!PolygonTexture.loadFromFile("imgs/start-page1/Polygon.png")) {
            return -1; // 텍스처 로드 실패 시 종료
        }

        // 배경 스프라이트에 텍스처 설정
        sf::Sprite backgroundSprite(backgroundTexture);
        sf::Sprite RectangleSprite(RectangleTexture);
        sf::Sprite PolygonSprite(PolygonTexture);

        // 사각형 크기 조정
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
        text2.setString(L"와 드드 진짜 연애도 못 하고 죽네....... 인생........");
        text2.setCharacterSize(40);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(390.f, 900.f);

        // 메인 루프
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                // 닫기 버튼 처리
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return -1;
                }

                // 마우스 클릭 처리
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // 클릭된 위치가 PolygonSprite 안에 있는지 확인
                        sf::FloatRect polygonBounds = PolygonSprite.getGlobalBounds();
                        if (polygonBounds.contains(event.mouseButton.x, event.mouseButton.y)) {
                            return 5; // 다음 페이지로 넘어감
                        }
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);
            window.draw(text1); // 텍스트 그리기
            window.draw(text2);

            // 화면 출력
            window.display();
        }

        return 1; // 기본 반환값 (예: 이전 페이지)
    }
};

#endif // START_PAGE4_H

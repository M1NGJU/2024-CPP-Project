#ifndef START_PAGE4_H
#define START_PAGE4_H

#include <SFML/Graphics.hpp>

class StartPage4 { // 클래스 이름과 파일명 일치
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
                        return 5; // 다음 페이지 번호 또는 종료 코드 반환
                    }
                }
            }

            // 화면 초기화
            window.clear(sf::Color::White);

            // 배경 그리기
            window.draw(backgroundSprite);
            window.draw(RectangleSprite);
            window.draw(PolygonSprite);

            // 화면 출력
            window.display();
        }

        return 1; // 기본 반환값 (예: 이전 페이지)
    }
};

#endif // START_PAGE4_H

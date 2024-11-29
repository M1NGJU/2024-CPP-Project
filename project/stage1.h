#ifndef stage1_H
#define stage1_H

#include <SFML/Graphics.hpp>

class stage1 {
public:
    static int run(sf::RenderWindow& parentWindow) {
        sf::RenderWindow& window = parentWindow;
        window.setTitle("stage1");

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("imgs/stage1/background.png")) {
            return -1;
        }

        // 글꼴 로드
        sf::Font font;
        if (!font.loadFromFile("font/Jua-Regular.ttf")) { // 사용할 글꼴 경로
            std::cout << "Failed to load font" << std::endl; // 디버그 메시지
            return -1; // 글꼴 로드 실패 시 종료
        }

        // 텍스트 생성
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"끼이이익 문이 열린다");
        text1.setCharacterSize(50); // 글자 크기 증가
        text1.setFillColor(sf::Color::Black); // 글자 색상

        // 텍스트를 화면 중앙에 배치
        sf::FloatRect textBounds = text1.getLocalBounds();
        float textX = (window.getSize().x - textBounds.width) / 2;
        float textY = (window.getSize().y - textBounds.height) / 2;
        text1.setPosition(textX, textY); // 중앙 위치 설정

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
            window.draw(text1);

            // 화면 출력
            window.display();
        }

        return 0;
    }
};

#endif

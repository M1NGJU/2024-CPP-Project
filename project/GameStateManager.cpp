#include "GameStateManager.h"

GameStateManager::GameStateManager() : currentState(GameState::START) {}

void GameStateManager::run() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // 현재 게임 상태에 따라 화면을 다르게 처리
        switch (currentState) {
        case GameState::START:
            handleStartScreen(window);
            break;
        case GameState::PAGE1:
            handlePage1Screen(window);
            break;
        }

        window.display();
    }
}

void GameStateManager::handleStartScreen(sf::RenderWindow& window) {
    start(window);  // start.cpp에서 화면 전환을 위한 함수를 호출 (start 화면)

    // 클릭 이벤트를 체크하여 startPage1로 이동
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        currentState = GameState::PAGE1;
    }
}

void GameStateManager::handlePage1Screen(sf::RenderWindow& window) {
    startPage1(window);  // startPage1.cpp에서 화면 전환을 위한 함수를 호출 (startPage1 화면)
}

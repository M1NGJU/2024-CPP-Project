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

        // ���� ���� ���¿� ���� ȭ���� �ٸ��� ó��
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
    start(window);  // start.cpp���� ȭ�� ��ȯ�� ���� �Լ��� ȣ�� (start ȭ��)

    // Ŭ�� �̺�Ʈ�� üũ�Ͽ� startPage1�� �̵�
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        currentState = GameState::PAGE1;
    }
}

void GameStateManager::handlePage1Screen(sf::RenderWindow& window) {
    startPage1(window);  // startPage1.cpp���� ȭ�� ��ȯ�� ���� �Լ��� ȣ�� (startPage1 ȭ��)
}

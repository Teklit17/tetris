#include "event.h"





void event::player2Controls(sf::RenderWindow& window, std::unique_ptr<Tetramino>& currentTetramino2,
                            std::array<std::array<int, 10>, 20>& board1, const sf::Event& event) {

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            currentTetramino2->move(-1, 0);
            if (currentTetramino2->isColliding(board1)) {
                currentTetramino2->move(1, 0);
            }
        }
        if (event.key.code == sf::Keyboard::Right) {
            currentTetramino2->move(1, 0);
            if (currentTetramino2->isColliding(board1)) {
                currentTetramino2->move(-1, 0);
            }
        }
        if (event.key.code == sf::Keyboard::Down) {
            currentTetramino2->move(0, 1);
            if (currentTetramino2->isColliding(board1)) {
                currentTetramino2->move(0, -1);
            }
        }
        if (event.key.code == sf::Keyboard::Up) {
            currentTetramino2->rotate();
            currentTetramino2->rotate(board1);
        }
    }
}

void event::player1Controls(sf::RenderWindow& window, std::unique_ptr<Tetramino>& currentTetramino1,
                            std::array<std::array<int, 10>, 20>& board2, const sf::Event& event) {

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::A) {
            currentTetramino1->move(-1, 0);
            if (currentTetramino1->isColliding(board2)) {
                currentTetramino1->move(1, 0);
            }
        }
        if (event.key.code == sf::Keyboard::D) {
            currentTetramino1->move(1, 0);
            if (currentTetramino1->isColliding(board2)) {
                currentTetramino1->move(-1, 0);
            }
        }
        if (event.key.code == sf::Keyboard::S) {
            currentTetramino1->move(0, 1);
            if (currentTetramino1->isColliding(board2)) {
                currentTetramino1->move(0, -1);
            }
        }
        if (event.key.code == sf::Keyboard::W) {
            currentTetramino1->rotate();
            currentTetramino1->rotate(board2);
        }
    }
}



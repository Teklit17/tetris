//
// Created by wadia on 5/10/2023.
//

#include "event.h"

void event::player1Controls(sf::RenderWindow& window,  std::unique_ptr<Tetramino>& currentTetramino1,  std::array<std::array<int, 10>, 20> board1f) {

    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                currentTetramino1->move(-1, 0);
                if (currentTetramino1->isColliding(board1f)) {
                    currentTetramino1->move(1, 0);
                }
            } else if (event.key.code == sf::Keyboard::Right) {
                currentTetramino1->move(1, 0);
                if (currentTetramino1->isColliding(board1f)) {
                    currentTetramino1->move(-1, 0);
                }
            } else if (event.key.code == sf::Keyboard::Down) {
                currentTetramino1->move(0, 1);
                if (currentTetramino1->isColliding(board1f)) {
                    currentTetramino1->move(0, -1);
                }
            } else if (event.key.code == sf::Keyboard::Up) {
                currentTetramino1->rotate(true);
            }
        }
    }
}


void event::player2Controls(sf::RenderWindow& window,  std::unique_ptr<Tetramino>& currentTetramino2,  std::array<std::array<int, 10>, 20> board2f) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::A) {
                currentTetramino2->move(-1, 0);
                if (currentTetramino2->isColliding(board2f)) {
                    currentTetramino2->move(1, 0);
                }
            } else if (event.key.code == sf::Keyboard::D) {
                currentTetramino2->move(1, 0);
                if (currentTetramino2->isColliding(board2f)) {
                    currentTetramino2->move(-1, 0);
                }
            } else if (event.key.code == sf::Keyboard::S) {
                currentTetramino2->move(0, 1);
                if (currentTetramino2->isColliding(board2f)) {
                    currentTetramino2->move(0, -1);
                }
            } else if (event.key.code == sf::Keyboard::W) {
                currentTetramino2->rotate(true);
            }
        }
    }
}

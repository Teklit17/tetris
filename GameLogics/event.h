//
// Created by wadia on 5/10/2023.
//

#ifndef TETRIS_EVENT_H
#define TETRIS_EVENT_H

#include <SFML/Graphics.hpp>
#include "../Tetraminos/Tetramino.h"
#include "../Board/Board.h"
#include <array>
#include <SFML/Audio.hpp>
#include <cmath>

class event {

public:

    void player1Controls(sf::RenderWindow& window, std::unique_ptr<Tetramino>& currentTetramino1, std::array<std::array<int, 10>, 20>& board1, const sf::Event& event);
    void player2Controls(sf::RenderWindow& window, std::unique_ptr<Tetramino>& currentTetramino2, std::array<std::array<int, 10>, 20>& board2, const sf::Event& event);
};

#endif //TETRIS_EVENT_H

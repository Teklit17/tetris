//
// Created by wadia on 5/10/2023.
//

#ifndef TETRIS_EVENT_H
#define TETRIS_EVENT_H

#include <SFML/Graphics.hpp>
#include "Tetramino.h"
#include "Board.h"
#include <array>
#include <SFML/Audio.hpp> // include the SFML Audio module
#include <cmath>


class event {

public:

    void player2Controls(sf::RenderWindow& window,  std::unique_ptr<Tetramino>& currentTetramino2,
                         std::array<std::array<int, 10>, 20> board2f);

    void player1Controls(sf::RenderWindow &window,  std::unique_ptr<Tetramino>& currentTetramino1,
                         std::array<std::array<int, 10>, 20> board1f);
};

#endif //TETRIS_EVENT_H

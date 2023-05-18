//
// Created by wadia on 5/10/2023.
//

#ifndef TETRIS_GAMELOOP_H
#include "../Board/Board.h"
#include "../audio/audio.h"
#include "RandomTetramino.h"
#include "../Tetraminos/Tetramino.h"
#include <array>
#include <SFML/Audio.hpp>
#include <cmath>
#include "../Menu/Menu.h"

class gameloop {
public:

    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;
    const int BLOCK_SIZE = 30;

    void drawBlocks1(sf::RenderWindow &window, std::unique_ptr<Tetramino> &currentTetramino1,std::array<std::array<int, 10>, 20> &boardf);
    void drawBlocks2(sf::RenderWindow &window, std::unique_ptr<Tetramino> &currentTetramino2,std::array<std::array<int, 10>, 20> &boardf);
    void moveTetraminoDown1(std::unique_ptr<Tetramino> &currentTetramino, std::array<std::array<int, 10>, 20> &board,Board &board1, RandomTetramino &Random, float &speed, sf::Clock &clock);
    void moveTetraminoDown2(std::unique_ptr<Tetramino> &currentTetramino, std::array<std::array<int, 10>, 20> &board,Board &board1, RandomTetramino &Random, float &speed, sf::Clock &clock);
    void clearFilledRows(std::array<std::array<int, 10>, 20> &board1f, int &score1, int &score2, Board &board1,Board &board2, sf::RenderWindow &window, sf::Font &font);
    void checkGameOver(sf::RenderWindow &window, Board &board1, Board &board2,

                       int &score1, int &score2,
                       const std::array<std::array<int, 10>, 20> &board1f,
                       const std::array<std::array<int, 10>, 20> &board2f,
                       sf::Font &font, Menu &menu);
};

#endif //TETRIS_GAMELOOP_H

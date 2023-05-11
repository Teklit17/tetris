//
// Created by wadia on 5/10/2023.
//

#ifndef TETRIS_GAMELOOP_H
#define TETRIS_GAMELOOP_H
#include "../Tetraminos/Board.h"
#include "../audio/audio.h"
#include "RandomTetramino.h"
#include "../Tetraminos/Tetramino.h"
#include <array>
#include <SFML/Audio.hpp> // include the SFML Audio module
#include <cmath>
#include "../Menu.h"


class gameloop {
public:
    void drawBlocks(sf::RenderWindow& window, std::unique_ptr<Tetramino>& currentTetramino, std::array<std::array<int, 10>, 20> boardf );
    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;

    const int BLOCK_SIZE = 30;
    void moveTetraminoDown(std::unique_ptr<Tetramino>& currentTetramino, std::array<std::array<int, 10>, 20>& board, Board& board1, RandomTetramino& Random, float& speed, sf::Clock& clock);
    void clearFilledRows(std::array<std::array<int, 10>, 20>& board1f, int& score, Board& board1, sf::RenderWindow& window, sf::Font& font);
    void checkGameOver(sf::RenderWindow& window, Board& board1, int score, std::array<std::array<int, 10>, 20>& board1f, sf::Font& font, Menu& menu);


    };


#endif //TETRIS_GAMELOOP_H

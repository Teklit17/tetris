//
// Created by wadia on 2/22/2023.
//

#ifndef TETRIS_RANDOMTETRAMINO_H
#define TETRIS_RANDOMTETRAMINO_H


#include "../Tetraminos/Tetramino.h"

class RandomTetramino {
public:
    std::unique_ptr<Tetramino> getRandomTetramino(sf::Color color, float x, float y, Board board);
};


#endif //TETRIS_RANDOMTETRAMINO_H

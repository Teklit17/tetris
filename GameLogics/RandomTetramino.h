//
// Created by wadia on 4/22/2023.
//
#ifndef TETRIS_RANDOMTETRAMINO_H
#define TETRIS_RANDOMTETRAMINO_H

#include "../Tetraminos/Tetramino.h"

class RandomTetramino {

public:
    std::unique_ptr<Tetramino> getRandomTetramino(sf::Color color, float x, float y, Board );
};

#endif //TETRIS_RANDOMTETRAMINO_H

//
// Created by wadia on 2/21/2023.
//

#ifndef TETRIS_Z_TETRAMINO_H
#define TETRIS_Z_TETRAMINO_H

#include "Tetramino.h"
#include <SFML/Graphics.hpp>
#include "Board.h"

class Z_Tetramino : public Tetramino {
public:
    Z_Tetramino(const sf::Color &color, int x, int y, Board board);
};


#endif //TETRIS_Z_TETRAMINO_H

//
// Created by wadia on 4/21/2023.
//

#ifndef TETRIS_L_TETRAMINO_H
#define TETRIS_L_TETRAMINO_H

#include "Tetramino.h"
#include <SFML/Graphics.hpp>
#include "../Board/Board.h"
 class L_Tetramino : public Tetramino {
    public:
        L_Tetramino(const sf::Color &color, int x, int y, Board board);
    };

#endif //TETRIS_L_TETRAMINO_H

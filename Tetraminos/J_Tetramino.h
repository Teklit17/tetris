//
// Created by wadia on 2/21/2023.
//

#ifndef TETRIS_J_TETRAMINO_H
#define TETRIS_J_TETRAMINO_H

#include "Tetramino.h"
#include <SFML/Graphics.hpp>
#include "Board.h"
class J_Tetramino : public Tetramino {
public:
    J_Tetramino(const sf::Color &color, int x, int y,Board board);
};


#endif //TETRIS_J_TETRAMINO_H

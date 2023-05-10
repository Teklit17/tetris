//
// Created by wadia on 2/21/2023.
//

#ifndef TETRIS_I_TETRAMINO_H
#define TETRIS_I_TETRAMINO_H

#include "Tetramino.h"
#include <SFML/Graphics.hpp>
#include "Board.h"

class I_Tetramino : public Tetramino
{
public:
    I_Tetramino(const sf::Color &color, int x, int y, Board board);


};



#endif //TETRIS_I_TETRAMINO_H

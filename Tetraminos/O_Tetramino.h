
//
// Created by wadia on 2/21/2023.
//

#ifndef TETRIS_O_TETRAMINO_H
#define TETRIS_O_TETRAMINO_H

#include "Tetramino.h"
#include <SFML/Graphics.hpp>
#include "Board.h"
class O_Tetramino : public Tetramino {
public:
    O_Tetramino(const sf::Color& color, int x, int y,Board board);
};


#endif //TETRIS_O_TETRAMINO_H

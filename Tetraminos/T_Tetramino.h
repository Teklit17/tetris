//
// Created by wadia on 4/21/2023.
//

#ifndef TETRIS_T_TETRAMINO_H
#define TETRIS_T_TETRAMINO_H
#include "Tetramino.h"
#include <SFML/Graphics.hpp>
#include "../Board/Board.h"

class T_Tetramino : public Tetramino {
public:
    T_Tetramino(const sf::Color& color, int x, int y,Board board);
};

#endif //TETRIS_T_TETRAMINO_H

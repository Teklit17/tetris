//
// Created by wadia on 4/21/2023.
//

#ifndef TETRIS_S_TETRAMINO_H
#define TETRIS_S_TETRAMINO_H

#include "Tetramino.h"
#include <SFML/Graphics.hpp>
#include "../Board/Board.h"

class S_Tetramino : public Tetramino {
public:
    S_Tetramino(const sf::Color& color, int x, int y,Board bord);
};

#endif //TETRIS_S_TETRAMINO_H

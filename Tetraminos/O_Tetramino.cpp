//
// Created by wadia on 4/21/2023.
//

#include "O_Tetramino.h"
#include "../Board/Board.h"

O_Tetramino::O_Tetramino(const sf::Color& color, int x, int y,Board m_board)
            : Tetramino({1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, color, x, y, m_board) {}


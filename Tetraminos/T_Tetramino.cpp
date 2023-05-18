//
// Created by wadia on 4/21/2023.
//

#include "T_Tetramino.h"

T_Tetramino::T_Tetramino(const sf::Color& color, int x, int y , Board m_board)  : Tetramino(
        {0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, color, x, y, m_board) {}
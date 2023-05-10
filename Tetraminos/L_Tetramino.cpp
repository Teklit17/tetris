//
// Created by wadia on 2/21/2023.
//

#include "L_Tetramino.h"
L_Tetramino::L_Tetramino(const sf::Color &color, int x, int y, Board m_board)
            : Tetramino({1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, color, x, y, m_board) {}

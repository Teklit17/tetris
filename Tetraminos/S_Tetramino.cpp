//
// Created by wadia on 4/21/2023.
//

#include "S_Tetramino.h"

S_Tetramino::S_Tetramino(const sf::Color& color, int x, int y, Board m_board)
            : Tetramino({0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, color, x, y, m_board) {}

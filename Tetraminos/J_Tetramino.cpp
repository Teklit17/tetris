//
// Created by wadia on 4/21/2023.
//

#include "../Board/Board.h"
#include "J_Tetramino.h"

  J_Tetramino::J_Tetramino(const sf::Color& color, int x, int y, Board m_board)
            : Tetramino({1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, color, x, y, m_board) {}

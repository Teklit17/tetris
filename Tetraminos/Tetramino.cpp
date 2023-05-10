//
// Created by wadia on 2/20/2023.
//

#include "Tetramino.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <chrono>


Tetramino::Tetramino(const std::array<int, 16> &shape, const sf::Color &color, int x, int y, const Board &mBoard)
        : m_shape(shape), m_color(color), m_x(x), m_y(y), m_board(mBoard) {
    m_block.setSize(sf::Vector2f(30.f, 30.f));
    m_block.setOutlineThickness(2.f);
    m_block.setOutlineColor(sf::Color::Black);
}

void Tetramino::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < m_shape.size(); ++i)
    {
        int x = i % 4;
        int y = i / 4;
        int color = m_shape[i];

        if (color != 0)
        {
            m_block.setFillColor(m_color);
            m_block.setPosition((m_x + x) * 30.f, (m_y + y) * 30.f);
            window.draw(m_block);
        }
    }
}

int Tetramino::get_block(int row, int col) const {
    int idx = row * 4 + col;
    return m_shape[idx];
}


void Tetramino::move(int xOffset, int yOffset) {

        // Update the position of the tetramino
        m_x += xOffset;
        m_y += yOffset;

        // Update the position of each block in the tetramino
        for (auto& block : m_blocks) {
            block.move(xOffset * BLOCK_SIZE, yOffset * BLOCK_SIZE);
        }
    }


int Tetramino::get_width() const {
    int width = 0;
    for (int col = 0; col < 4; col++) {
        bool has_block = false;
        for (int row = 0; row < 4; row++) {
            if (get_block(row, col) != 0) {
                has_block = true;
                break;
            }
        }
        if (has_block) {
            width++;
        }
    }
    return width;
}


void Tetramino::rotate(bool clockwise) {
    std::array<int, 16> new_shape = m_shape;
    for (int i = 0; i < 16; i++) {
        int row = i / 4;
        int col = i % 4;
        int new_row = 3 - col;
        int new_col = row;
        int new_idx = new_row * 4 + new_col;
        new_shape[new_idx] = m_shape[i];
    }

    int left = m_x;
    int right = m_x + get_width();
    if (right > Board::WIDTH) {
        m_x = Board::WIDTH - get_width();
    } else if (left < 0) {
        m_x = 0;
    }

    m_shape = new_shape;
}







bool Tetramino::isColliding(const std::array<std::array<int, 10>, 20> &board) const {
    for (int i = 0; i < 16; i++) {
        int row = i / 4;
        int col = i % 4;
        int board_row = m_y + row;
        int board_col = m_x + col;
        if (m_shape[i] == 1) {
            if (board_row >= Board::HEIGHT || board[board_row][board_col] == 1) {
                return true;
            }
            // Check if the tetramino is out of the game board bounds
            if (board_row < 0 || board_row >= Board::HEIGHT ||
                board_col < 0 || board_col >= Board::WIDTH) {
                return true;
            }


        }
    }
    return false;
}







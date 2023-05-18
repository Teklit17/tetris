//
// Created by wadia on 4/20/2023.
//
#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Board/Board.h"

class Tetramino {

    public:
    static const int BLOCK_SIZE = 10;
    static const int NUM_BLOCKS = 4;
    const Board& m_board;
    int m_x;
    int m_y;
    int get_block(int row, int col) const;
    int get_width() const;
    int getY() const { return m_y; }
    int get_height() const;

    bool isColliding(const std::array<std::array<int, 10>, 20> &board)const;
    void draw(sf::RenderWindow& window, int x_offset);
    void move(int xOffset, int yOffset);
    void rotate(const std::array<std::array<int, 10>, 20>& board);
    Tetramino(const std::array<int, 16> &shape, const sf::Color &color, int x, int y, const Board &mBoard);
    void rotate();

    std::array<int, 16> m_shape;
    sf::Color m_color;
    sf::RectangleShape m_block;
    std::vector<sf::Vector2i> m_blockOffsets;
    std::vector<sf::RectangleShape> m_blocks;


};

#endif //TETRIS_TETRAMINO_H

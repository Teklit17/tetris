//
// Created by wadia on 2/20/2023.
//

#ifndef TETRIS_TETRAMINO_H
#define TETRIS_TETRAMINO_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
class Tetramino {

    public:

    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;
    static const int BLOCK_SIZE = 10;
    static const int NUM_BLOCKS = 4;
    const Board& m_board;
    Tetramino(const std::array<int, 16> &shape, const sf::Color &color, int x, int y, const Board &mBoard);

    std::vector<sf::RectangleShape> getBlocks() const;


    int get_block(int row, int col) const;
    int get_width() const;
    bool isColliding(const std::array<std::array<int, 10>, 20> &board)const;
    void draw(sf::RenderWindow& window);
    void move(int xOffset, int yOffset);
    void rotate(bool clockwise);
    int getY() const { return m_y; }
    std::array<int, 16> m_shape;
        sf::Color m_color;
        int m_x;
        int m_y;
        sf::RectangleShape m_block;
    std::vector<sf::Vector2i> m_blockOffsets;

    std::vector<sf::RectangleShape> m_blocks;
};


#endif //TETRIS_TETRAMINO_H

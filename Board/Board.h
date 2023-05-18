//
// Created by wadia on 2/22/2023.
//
#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Board {
public:
    int X_OFFSET = 0;
    static const int WIDTH = 10;
    static const int HEIGHT = 20;
    static const int BLOCK_SIZE = 30;
    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;
    const float INITIAL_SPEED = 0.5f;
    Board();

    void draw(sf::RenderWindow& window);
    void drawBoard(sf::RenderWindow& window);
    void drawPlayer1Name(sf::RenderWindow& window, sf::Font& font);
    void drawPlayer2Name(sf::RenderWindow& window, sf::Font& font);
    void updatePlayer2ScoreText(int player2Score,sf::RenderWindow& window, sf::Font& font);
    void updatePlayer1ScoreText(int player1Score,sf::RenderWindow& window, sf::Font& font);
    void  gameOvertext(sf::RenderWindow& window, sf::Font& font);
    void  gameOvertext2(sf::RenderWindow& window, sf::Font& font);
    void  gameOvertextDraw(sf::RenderWindow& window, sf::Font& font);
    bool isGameOver(const std::array<std::array<int, 10>, 20> &board, const std::array<std::array<int, 10>, 20> array) const;

private:
    int m_cells[WIDTH][HEIGHT];
    sf::RectangleShape m_cellShape;
    std::array<std::array<int, 10>, 20> board;
};

#endif //TETRIS_BOARD_H

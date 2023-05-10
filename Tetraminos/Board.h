//
// Created by wadia on 2/22/2023.
//
#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Board {
public:
    static const int WIDTH = 10;
    static const int HEIGHT = 20;
    static const int BLOCK_SIZE = 30;
    static const int SHAPE_SIZE= 4;
    int counter = 0;
    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;
    // Set the initial falling speed
    const float INITIAL_SPEED = 0.5f;
    float speed = INITIAL_SPEED;
    int numClearedRows = 0;
    int score = 0;
    int player1Score = 0;
    int player2Score = 0;
    bool gameOver = false;
    const int MAX_SCORE = 50;
    Board();



    void GameOverMessage(sf::RenderWindow& window, sf::Font& font, int highScore);



    void draw(sf::RenderWindow& window);
    void drawBoard(sf::RenderWindow& window);


// draw which player is which
    void drawPlayer1Name(sf::RenderWindow& window, sf::Font& font);
    void drawPlayer2Name(sf::RenderWindow& window, sf::Font& font);


    // update score for the Players
    void updatePlayer2ScoreText(int player2Score,sf::RenderWindow& window, sf::Font& font);
    void updatePlayer1ScoreText(int player1Score,sf::RenderWindow& window, sf::Font& font);

    void  gameOvertext(sf::RenderWindow& window, sf::Font& font);
    bool isGameOver(const std::array<std::array<int, 10>, 20> &board) const;

private:
    int m_cells[WIDTH][HEIGHT];
    sf::RectangleShape m_cellShape;
};

#endif //TETRIS_BOARD_H

//
// Created by wadia on 2/22/2023.
//

#include "Board.h"
#include "../Tetraminos/Tetramino.h"

void Board::drawBoard(sf::RenderWindow& window) {
    window.clear(sf::Color::White);
    sf::VertexArray line1(sf::Lines, 2);
    line1[0].position = sf::Vector2f(10 * BLOCK_SIZE, 0);
    line1[1].position = sf::Vector2f(10 * BLOCK_SIZE, 20 * BLOCK_SIZE);
    line1[0].color = sf::Color::Black;
    line1[1].color = sf::Color::Black;
    window.draw(line1);

    sf::VertexArray line2(sf::Lines, 2);
    line2[0].position = sf::Vector2f(20 * BLOCK_SIZE, 0);
    line2[1].position = sf::Vector2f(20 * BLOCK_SIZE, 20 * BLOCK_SIZE);
    line2[0].color = sf::Color::Black;
    line2[1].color = sf::Color::Black;
    window.draw(line2);
    draw(window);
}
void Board::drawPlayer1Name(sf::RenderWindow& window, sf::Font& font) {
    sf::Text textPlayer1("Player 1", font);
    textPlayer1.setCharacterSize(24);
    textPlayer1.setFillColor(sf::Color::Black);
    textPlayer1.setStyle(sf::Text::Regular);
    textPlayer1.setPosition(30, 5);
    window.draw(textPlayer1);
}
void Board::drawPlayer2Name(sf::RenderWindow& window, sf::Font& font) {
    sf::Text textPlayer1("Player 2", font);
    textPlayer1.setCharacterSize(24);
    textPlayer1.setFillColor(sf::Color::Black);
    textPlayer1.setStyle(sf::Text::Regular);
    textPlayer1.setPosition(330, 5);
    window.draw(textPlayer1);
}
void Board::updatePlayer1ScoreText(int player1Score,sf::RenderWindow& window, sf::Font& font)
{
    sf::Text textPlayer1Score("Score: " + std::to_string(player1Score), font);
    textPlayer1Score.setCharacterSize(24);
    textPlayer1Score.setFillColor(sf::Color::Red);
    textPlayer1Score.setStyle(sf::Text::Regular);
    textPlayer1Score.setPosition(30, 50);
    window.draw(textPlayer1Score);
}
void Board::updatePlayer2ScoreText(int player2Score,sf::RenderWindow& window, sf::Font& font)
{
    sf::Text textPlayer2Score("Score: " + std::to_string(player2Score), font);
    textPlayer2Score.setCharacterSize(24);
    textPlayer2Score.setFillColor(sf::Color::Red);
    textPlayer2Score.setStyle(sf::Text::Regular);
    textPlayer2Score.setPosition(BOARD_WIDTH * 2 * BLOCK_SIZE -270, 50);
    textPlayer2Score.setFont(font);
    window.draw(textPlayer2Score);
}
void Board::gameOvertext(sf::RenderWindow& window, sf::Font& font) {
    sf::Text gameOverText("Player 1 Wins!", font);
    gameOverText.setCharacterSize(58);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(BOARD_WIDTH * BLOCK_SIZE / 2 - 150, BOARD_HEIGHT * BLOCK_SIZE / 2 - 24);
    window.draw(gameOverText);
}
void Board::gameOvertext2(sf::RenderWindow& window, sf::Font& font) {
    sf::Text gameOverText("Player 2 Wins!", font);
    gameOverText.setCharacterSize(58);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(BOARD_WIDTH * BLOCK_SIZE / 2 - 150, BOARD_HEIGHT * BLOCK_SIZE / 2 - 24);
    window.draw(gameOverText);
}
void Board::gameOvertextDraw(sf::RenderWindow& window, sf::Font& font) {
    sf::Text gameOverText("The Game is draw, same score:)!", font);
    gameOverText.setCharacterSize(58);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(BOARD_WIDTH * BLOCK_SIZE / 2 - 150, BOARD_HEIGHT * BLOCK_SIZE / 2 - 24);
    window.draw(gameOverText);
}
Board::Board()
{
    for (int x = 0; x < WIDTH; ++x)
    {
        for (int y = 0; y < HEIGHT; ++y)
        {
            m_cells[x][y] = 0;
        }
    }
    m_cellShape.setSize(sf::Vector2f(Tetramino::BLOCK_SIZE, Tetramino::BLOCK_SIZE));
    m_cellShape.setOutlineThickness(1.f);
    m_cellShape.setOutlineColor(sf::Color::Black);
}
void Board::draw(sf::RenderWindow& window)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            if (m_cells[x][y] != 0)
            {
                m_cellShape.setPosition(x * Tetramino::BLOCK_SIZE, y * Tetramino::BLOCK_SIZE);
                m_cellShape.setFillColor(sf::Color::Blue);
                window.draw(m_cellShape);
            }
        }
    }
}
    bool Board::isGameOver(const std::array<std::array<int, 10>, 20> &board,const std::array<std::array<int, 10>, 20> array) const {
        for (int col = 0; col < WIDTH; col++) {
            if (board[0][col] == 1) {
                return true;
            }
        }
        return false;
    }

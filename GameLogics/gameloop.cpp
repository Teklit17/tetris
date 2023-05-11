//
// Created by wadia on 5/10/2023.
//

#include "gameloop.h"

void gameloop::moveTetraminoDown(std::unique_ptr<Tetramino>& currentTetramino, std::array<std::array<int, 10>, 20>& board, Board& board1, RandomTetramino& Random, float& speed, sf::Clock& clock) {
    audio soundPlayer;
    const float INITIAL_SPEED = 0.5f;

    // Move the tetramino down automatically
    if (clock.getElapsedTime().asSeconds() >= 1.f) {
        currentTetramino->move(0, 1);
        //soundPlayer.SoundMoveDown();
        clock.restart();
    }
    // Move the tetramino downwards at a certain speed,
    // and check if it has collided with any other tetrominos on the board.
    if (clock.getElapsedTime().asSeconds() >= speed) {
        currentTetramino->m_y++;
        if (currentTetramino->isColliding(board)) {
            currentTetramino->m_y--;
            for (int i = 0; i < 16; i++) {
                int row = i / 4;
                int col = i % 4;
                int board_row = currentTetramino->m_y + row;
                int board_col = currentTetramino->m_x + col;
                if (currentTetramino->m_shape[i] == 1) {
                    board[board_row][board_col] = 1;
                }
            }
            soundPlayer.SoundMove();
            currentTetramino = Random.getRandomTetramino(sf::Color::Green, 5, 0, board1);
        }
        //soundPlayer.SoundMoveDown();
        clock.restart();
    }
}
audio S;
void gameloop::clearFilledRows(std::array<std::array<int, 10>, 20>& board1f, int& score, Board& board1, sf::RenderWindow& window, sf::Font& font) {
    audio soundPlayer;
    //soundPlayer.playSoundP();

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        bool rowFilled = true;
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board1f[i][j] == 0) {
                rowFilled = false;
                break;
            }
        }
        if (rowFilled) {
            // Clear the row
            for (int j = 0; j < BOARD_WIDTH; j++) {
                board1f[i][j] = 0;
            }
            // Move down blocks above the cleared row
            for (int k = i - 1; k >= 0; k--) {
                for (int j = 0; j < BOARD_WIDTH; j++) {
                    board1f[k + 1][j] = board1f[k][j];
                    board1f[k][j] = 0;
                }
            }
            // Increase the score
            soundPlayer.playSoundPoint();
            score += 10;
            board1.updatePlayer1ScoreText(score, window, font);
        }
    }
}
void gameloop::checkGameOver(sf::RenderWindow& window, Board& board1, int score, std::array<std::array<int, 10>, 20>& board1f, sf::Font& font, Menu& menu) {
    board1.drawBoard(window);
    audio soundPlayer;

    if (board1.isGameOver(board1f)) {
        window.clear();
        // Draw the game over text
        board1.gameOvertext(window, font);

        board1.updatePlayer1ScoreText(score, window, font);
        // Display the window
        window.display();
        soundPlayer.SoundGameOver();
        std::cout << "game over";

        sf::Clock clock;
        bool menuShown = false;

        while (!menuShown) {
            sf::Time elapsed = clock.getElapsedTime();
            if (elapsed.asSeconds() >= 3.0) {
                menu.showMenu(window);
                menuShown = true;
            }
        }
        menu.showMenu(window);
    }
}
void gameloop::drawBlocks(sf::RenderWindow& window, std::unique_ptr<Tetramino>& currentTetramino, std::array<std::array<int, 10>, 20> boardf ) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (boardf[i][j] == 1) {
                sf::RectangleShape block(currentTetramino->m_block);
                block.setPosition(j * BLOCK_SIZE, i * BLOCK_SIZE);
                block.setFillColor(currentTetramino->m_color);
                window.draw(block);
            }
        }
    }
}


//
// Created by wadia on 5/10/2023.
//

#include "gameloop.h"

void gameloop::moveTetraminoDown2(std::unique_ptr<Tetramino>& currentTetramino, std::array<std::array<int, 10>, 20>& board1, Board& board,RandomTetramino& Random, float& speed, sf::Clock& clock){
    audio soundPlayer;

    if (clock.getElapsedTime().asSeconds() >= 1.f) {
        currentTetramino->move(0, 1);
        clock.restart();
    }
    if (clock.getElapsedTime().asSeconds() >= speed) {
        currentTetramino->m_y++;
        if (currentTetramino->isColliding(board1)) {
            currentTetramino->m_y--;
            for (int i = 0; i < 16; i++) {
                int row = i / 4;
                int col = i % 4;
                int board_row = currentTetramino->m_y + row;
                int board_col = currentTetramino->m_x + col;
                if (currentTetramino->m_shape[i] == 1) {
                    board1[board_row][board_col] = 1;
                }
            }
            soundPlayer.SoundMove();
            currentTetramino = Random.getRandomTetramino
                    (sf::Color::Green, 5, 0, board);
        }
        clock.restart();
    }
}
void gameloop::moveTetraminoDown1(std::unique_ptr<Tetramino>& currentTetramino, std::array<std::array<int, 10>, 20>& board2, Board& board,RandomTetramino& Random, float& speed, sf::Clock& clock){
    audio soundPlayer;
    if (clock.getElapsedTime().asSeconds() >= 1.f) {
        currentTetramino->move(0, 1);
        clock.restart();
    }
    if (clock.getElapsedTime().asSeconds() >= speed) {
        currentTetramino->m_y++;
        if (currentTetramino->isColliding(board2)) {
            currentTetramino->m_y--;
            for (int i = 0; i < 16; i++) {
                int row = i / 4;
                int col = i % 4;
                int board_row = currentTetramino->m_y + row;
                int board_col = currentTetramino->m_x + col;
                if (currentTetramino->m_shape[i] == 1) {
                    board2[board_row][board_col] = 1;
                }
            }
            soundPlayer.SoundMove();
            currentTetramino = Random.getRandomTetramino
                    (sf::Color::Green, 5, 0, board);
        }
        clock.restart();
    }
}
void gameloop::clearFilledRows(std::array<std::array<int, 10>, 20>& board1f,int& score1, int& score2, Board& board1, Board& board2, sf::RenderWindow& window, sf::Font& font) {
    audio soundPlayer;
    int rowsClearedPlayer1 = 0;
    int rowsClearedPlayer2 = 0;

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        bool rowFilled = true;
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board1f[i][j] == 0) {
                rowFilled = false;
                break;
            }
        }
        if (rowFilled) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                board1f[i][j] = 0;
            }
            for (int k = i - 1; k >= 0; k--) {
                for (int j = 0; j < BOARD_WIDTH; j++) {
                    board1f[k + 1][j] = board1f[k][j];
                    board1f[k][j] = 0;
                }
            }
            if (i < BOARD_WIDTH * 2) {
                soundPlayer.playSoundPoint();
                score1 += 10;
                board1.updatePlayer1ScoreText(score1, window, font);
            } else {
                soundPlayer.playSoundPoint();
                score2 += 10;
            }
        }
    }
}
void gameloop::checkGameOver(sf::RenderWindow& window, Board& board1, Board& board2,int& score1, int& score2,const std::array<std::array<int, 10>, 20>& board1f,const std::array<std::array<int, 10>, 20>& board2f,sf::Font& font, Menu& menu){
    audio soundPlayer;
    if (board1.isGameOver(board1f, board2f) || board2.isGameOver(board2f, board1f)) {

        window.clear();
        {
            if (score1 > score2) {
                board1.gameOvertext(window, font);
            } else if (score2 > score1) {
                board2.gameOvertext2(window, font);
            } else {
                board2.gameOvertextDraw(window, font);}
        }
        score1 = 0;
        score2 = 0;
        window.display();
        soundPlayer.SoundGameOver();

        sf::Clock clock;
        bool menuShown = false;

        while (!menuShown) {
            sf::Time elapsed = clock.getElapsedTime();
            if (elapsed.asSeconds() >= 4.0) {
                menu.showMenu(window);
                menuShown = true;
            }
        }
        menu.showMenu(window);
        return;
    }
}
void gameloop::drawBlocks1(sf::RenderWindow& window, std::unique_ptr<Tetramino>& currentTetramino1,std::array<std::array<int, 10>, 20>& boardf ) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (boardf[i][j] == 1) {
                sf::RectangleShape block(currentTetramino1->m_block);
                block.setPosition(j * BLOCK_SIZE, i * BLOCK_SIZE);
                block.setFillColor(currentTetramino1->m_color);
                window.draw(block);
            }
        }
    }
}
void gameloop::drawBlocks2(sf::RenderWindow& window, std::unique_ptr<Tetramino>& currentTetramino2,
                          std::array<std::array<int, 10>, 20>& boardf) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (boardf[i][j] == 1) {
                sf::RectangleShape block(currentTetramino2->m_block);
                if (currentTetramino2->m_x < BOARD_WIDTH)  {
                    block.setPosition((j + BOARD_WIDTH) * BLOCK_SIZE, i * BLOCK_SIZE);
                }
                block.setFillColor(currentTetramino2->m_color);
                window.draw(block);
            }
        }
    }
}


#include <SFML/Graphics.hpp>
#include "Board/Board.h"
#include "GameLogics/RandomTetramino.h"
#include <array>
#include "Menu/Menu.h"
#include <SFML/Audio.hpp>
#include <cmath>
#include "GameLogics/gameloop.h"
#include "GameLogics/event.h"


int main() {

    const int BLOCK_SIZE = 30;
    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;
    const float INITIAL_SPEED = 0.5f;
    float speed = INITIAL_SPEED;
    int score1 = 0;
    int score2 = 0;

    Menu menu;
    RandomTetramino Random;
    event event1, event2;
    gameloop gameloop1;
    Board board1;
    Board board2;
    board2.X_OFFSET = BOARD_WIDTH;


    sf::CircleShape pivotCircle(5);
    sf::RenderWindow window(sf::VideoMode
    (BOARD_WIDTH * 3 * BLOCK_SIZE, BOARD_HEIGHT * BLOCK_SIZE), "Tetramino");
    menu.showMenu(window);

    sf::Font font;
    if (!font.loadFromFile("SFML/bin/Montserrat-Italic-VariableFont_wght.ttf")) {
        return EXIT_FAILURE;
    }
    auto currentTetramino1 = Random.getRandomTetramino(sf::Color::Green, 5, 0, board1);
    auto currentTetramino2 = Random.getRandomTetramino(sf::Color::Blue,  5, 0, board2);

    std::array<std::array<int, BOARD_WIDTH>, BOARD_HEIGHT> board1f{};
    std::array<std::array<int, BOARD_WIDTH>, BOARD_HEIGHT> board2f{};
    sf::Clock clock1;
    sf::Clock clock2;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                event2.player2Controls(window, currentTetramino2, board2f, event);
            }
            if (event.type == sf::Event::KeyPressed) {
                event1.player1Controls(window, currentTetramino1, board1f, event);
            }
            if (event.type == sf::Event::KeyReleased) {
                event1.player1Controls(window, currentTetramino1, board1f, event);
            }
            if (event.type == sf::Event::KeyReleased) {
                event2.player2Controls(window, currentTetramino2, board2f, event);
            }
        }
        gameloop1.moveTetraminoDown1(currentTetramino1, board1f, board1, Random, speed, clock1);
        gameloop1.moveTetraminoDown2(currentTetramino2, board2f, board2,Random, speed, clock2);
        board1.drawBoard(window);

        gameloop1.checkGameOver(window, board1, board2, score1, score2, board1f, board2f, font, menu);
        gameloop1.clearFilledRows(board1f, score1, score2, board1, board2, window, font);
        gameloop1.clearFilledRows(board2f, score2,score1, board2, board1, window, font);

        board1.updatePlayer1ScoreText(score1, window, font);
        board2.updatePlayer2ScoreText(score2, window, font);
        board1.drawPlayer1Name(window, font);
        board2.drawPlayer2Name(window, font);

        gameloop1.drawBlocks1(window, currentTetramino1, board1f);
        gameloop1.drawBlocks2(window, currentTetramino2, board2f);

        currentTetramino1->draw(window, 0);
        currentTetramino2->draw(window, 10);

        if (board1.isGameOver(board1f, std::array<std::array<int, 10>, 20>())) {
            currentTetramino1 = Random.getRandomTetramino
                    (sf::Color::Green, 5, 0, board1);
            board1f.fill({0});
        }
        if (board2.isGameOver(board2f, std::array<std::array<int, 10>, 20>())) {
            currentTetramino2 = Random.getRandomTetramino
                    (sf::Color::Green, 5, 0, board2);
            board2f.fill({0});
        }
        window.display();
    }
    system("pause");
    return 0;
}

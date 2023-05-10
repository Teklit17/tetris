#include <SFML/Graphics.hpp>
#include "Tetraminos/Tetramino.h"
#include "Tetraminos/Board.h"
#include "GameLogics/RandomTetramino.h"
#include <array>
#include "Menu.h"
#include <SFML/Audio.hpp> // include the SFML Audio module
#include <cmath>
#include "GameLogics/gameloop.h"

#include "Tetraminos/event.h"


int main() {


    const int BLOCK_SIZE = 30;
    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;
    const float INITIAL_SPEED = 0.5f;
    float speed = INITIAL_SPEED;

    int score = 0;


    Menu menu;
    Board board1;
    Board board2;
    RandomTetramino Random;
    event event1;
    gameloop gameloop1;


    sf::CircleShape pivotCircle(5);
    sf::RenderWindow window(sf::VideoMode(BOARD_WIDTH * 3 * BLOCK_SIZE, BOARD_HEIGHT * BLOCK_SIZE), "Tetramino");
    menu.showMenu(window);


    sf::Font font;
    if (!font.loadFromFile("../SFML/bin/Font/Montserrat-Italic-VariableFont_wght.ttf")) {
        return EXIT_FAILURE;
    }

    // Create the first tetramino
    auto currentTetramino1 = Random.getRandomTetramino(sf::Color::Green, 5, 0, board1);
    auto currentTetramino2 = Random.getRandomTetramino(sf::Color::Blue, BOARD_WIDTH + 5, 0, board2);

    std::array<std::array<int, BOARD_WIDTH>, BOARD_HEIGHT> board1f{};
    std::array<std::array<int, BOARD_WIDTH>, BOARD_HEIGHT> board2f{};

    // Create a clock to measure the time elapsed since the last tetramino movement
    sf::Clock clock1;
    sf::Clock clock2;


    while (window.isOpen()) {


        event1.player1Controls(window, currentTetramino1, board1f);

        gameloop1.moveTetraminoDown(currentTetramino1, board1f, board1, Random, speed, clock1);
        gameloop1.clearFilledRows(board1f, score, board1, window, font);


        board1.drawBoard(window);
        board2.drawBoard(window);


        gameloop1.checkGameOver(window, board1, score, board1f, font, menu);



        // Draw the player 1 score and name
        board1.updatePlayer1ScoreText(score, window, font);
        board1.drawPlayer1Name(window, font);
        board1.drawPlayer2Name(window, font);

        gameloop1.drawBlocks(window, currentTetramino1, board1f);



        // Draw the current tetramino
        currentTetramino1->draw(window);
        currentTetramino2->draw(window);


        window.display();
    }
    system("pause");
    return 0;
}

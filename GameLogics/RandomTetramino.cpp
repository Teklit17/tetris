//
// Created by wadia on 4/22/2023.
//
#include "RandomTetramino.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include "../Tetraminos/I_Tetramino.h"
#include "../Tetraminos/L_Tetramino.h"
#include "../Tetraminos/Z_Tetramino.h"
#include "../Tetraminos/J_Tetramino.h"
#include "../Tetraminos/O_Tetramino.h"
#include "../Tetraminos/S_Tetramino.h"
#include "../Tetraminos/T_Tetramino.h"

std::unique_ptr<Tetramino> RandomTetramino::getRandomTetramino(sf::Color color, float x, float y, Board board) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 6);

    switch (dist(gen)) {
        case 0:
            return std::make_unique<I_Tetramino>(sf::Color::Green, x, y, board);
        case 1:
            return std::make_unique<L_Tetramino>(sf::Color::Red, x, y, board);
        case 2:
            return std::make_unique<Z_Tetramino>(sf::Color::Magenta, x, y, board);
        case 3:
            return std::make_unique<J_Tetramino>(sf::Color::Yellow, x, y, board);
        case 4:
            return std::make_unique<O_Tetramino>(sf::Color::Blue, x, y, board);
        case 5:
            return std::make_unique<S_Tetramino>(sf::Color::Cyan, x, y, board);
        default:
            return std::make_unique<T_Tetramino>(sf::Color::Cyan, x, y, board);
    }
}
//
// Created by wadia on 5/10/2023.
//

#ifndef TETRIS_MENU_H
#define TETRIS_MENU_H

#include <SFML/Graphics.hpp>
#include "../Tetraminos/Tetramino.h"
#include "../Board/Board.h"
#include "../GameLogics/RandomTetramino.h"
#include <array>
#include "Menu.h"
#include <SFML/Audio.hpp>

class Menu {
public:

    void showMenu(sf::RenderWindow& window);
};

#endif //TETRIS_MENU_H

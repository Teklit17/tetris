#include "Menu.h"
#include "audio/audio.h"

void Menu::showMenu(sf::RenderWindow& window) {
    bool selecting = true;
    sf::Font font;
    if (!font.loadFromFile("Montserrat-Italic-VariableFont_wght.ttf")) {
        std::cout << "Error loading font" << std::endl;
        return;
    }
audio soundPlayer;
    soundPlayer.playSoundMenu();
    sf::Text title("Menu", font, 48);
    title.setPosition(200, 200);

    sf::Text start("Start game", font, 24);
    start.setPosition(200, 300);

    sf::Text singleplayer("Singleplayer", font, 24);
    singleplayer.setPosition(200, 350);

    sf::Text multiplayer("Multiplayer", font, 24);
    multiplayer.setPosition(200, 400);

    sf::Text quit("Quit", font, 24);
    quit.setPosition(200, 450);


    while (selecting) {
        window.clear();

        window.draw(start);
        window.draw(singleplayer);
        window.draw(multiplayer);
        window.draw(quit);
        window.display();

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                selecting = false;
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (start.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Start game
                        selecting = false;
                    } else if (singleplayer.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Start singleplayer game
                        selecting = false;
                    } else if (multiplayer.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Start multiplayer game
                        selecting = false;
                    } else if (quit.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                        soundPlayer.stopSound();
                        selecting = false;
                    }
                }
            }
        }
    }PlaySound(NULL, NULL, SND_ASYNC);

}

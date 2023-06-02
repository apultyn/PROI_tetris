#include <SFML/Graphics.hpp>
#include "playfield.h"
#include "Tetromino.h"
#include <iostream>
#include "Game.h"
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "Window.h"
#include "Menu.h"

int main()
{
    Window window;
    Menu menu(window);
    int level = menu.openMenu();
    Game game(window, level);
    int choice = game.startGame();
    while (choice != CLOSE)
    {
        if (choice == RESTART)
        {
            Game game(window, level);
            choice = game.startGame();
        }
        else if (choice == CHANGE_LVL)
        {
            Menu menu(window);
            level = menu.openMenu();
            Game game(window, level);
            choice = game.startGame();
        }
    }
    window.getWindow().close();

    return 0;
}
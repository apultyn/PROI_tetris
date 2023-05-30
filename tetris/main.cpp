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
    menu.openMenu();
    return 0;
}
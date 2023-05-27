#include <SFML/Graphics.hpp>
#include "playfield.h"
#include "Tetromino.h"
#include <iostream>
#include "Game.h"
#include <chrono>
#include <thread>
#include <stdlib.h>


int main()
{

    Game game;
    Playfield playfield;
    game.setPlayfield(playfield);
    game.initWindow();
    game.startGame();

    return 0;
}
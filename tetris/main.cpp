#include <SFML/Graphics.hpp>
#include "playfield.h"
#include "Tetrominoes.h"
#include <iostream>
#include "Game.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH * RESIZE * CELL_SIZE, VISIBLE_HEIGHT * RESIZE * CELL_SIZE), "Tetris");
    Playfield playfield;
    Tetromino piece('I');
    piece.updateMatrix(playfield.getPlayfield()); // places a tetrominoe in matrix
    Game game;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();                 
        game.drawPlayfield(playfield, window); // prints the matrix
        window.display();

    }



    return 0;
}
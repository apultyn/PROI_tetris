#include <SFML/Graphics.hpp>
#include "playfield.h"
#include "Tetrominoes.h"
#include <iostream>
#include "Game.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH * RESIZE * CELL_SIZE, VISIBLE_HEIGHT * RESIZE * CELL_SIZE), "Tetris");
    Playfield playfield;
    Tetromino piece('T');
    //piece.updateMatrix(playfield.getPlayfield()); // places a tetrominoe in matrix
    Game game;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            std::cout << playfield.getPlayfield()[i][j];
        }
        std::cout << std::endl;
    }



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();                 
       // game.drawPlayfield(playfield, window); // prints the matrix
        game.drawTetromino(piece, window);
        window.display();

    }



    return 0;
}
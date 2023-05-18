#include <SFML/Graphics.hpp>
#include "playfield.h"
#include "Tetrominoes.h"
#include <iostream>
#include "Game.h"
#include <chrono>
#include <thread>



int main()
{

    // maybe new class - Window/Menu?

    sf::RenderWindow window(sf::VideoMode(WIDTH * RESIZE * CELL_SIZE * 2, VISIBLE_HEIGHT * RESIZE * CELL_SIZE), "Tetris");
    Playfield playfield;

    // Piece generator needed

    Tetromino piece('Z');
    Game game;

    // print the main matrix in terminal
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
        game.drawPlayfield(playfield, window); // prints the matrix
        game.drawTetromino(piece, window);


        // have to change waiting time
        // maybe move it to another class?

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            piece.rotate_right();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            piece.rotate_left();

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            piece.moveRight();

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            piece.moveLeft();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        piece.moveDown();
        window.display();

    }



    return 0;
}
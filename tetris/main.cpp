#include <SFML/Graphics.hpp>
#include "playfield.h"
#include "Tetromino.h"
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
            std::cout << playfield.playfield_matrix[i][j];
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

        sf::Clock clock;
        // have to change waiting time
        // maybe move it to another class?
 
        while (clock.getElapsedTime().asMilliseconds() <= 500)
        {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            piece.rotate_right();
 
            window.clear();
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);

            //window.display();

            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            piece.rotate_left();
            window.clear();
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);
            break;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            piece.moveRight();
            //if (!playfield.correctPos(piece))
            //{
            //    piece.moveLeft();
            //}
            window.clear();
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);
            break;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            piece.moveLeft();
            //if (!playfield.correctPos(piece))
            //{
            //    piece.moveRight();
            //}
            window.clear();
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);
            break;
        }
        
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500 - clock.getElapsedTime().asMilliseconds()));
        piece.moveDown();
   
        window.display();


    }



    return 0;
}
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

    // maybe new class - Window/Menu?

    sf::RenderWindow window(sf::VideoMode(WIDTH * RESIZE * CELL_SIZE * 2, VISIBLE_HEIGHT * RESIZE * CELL_SIZE), "Tetris");
    Playfield playfield;

    // Piece generator needed

    
    Game game;
    Tetromino piece = game.getNewTetromino();




    while (window.isOpen())
    {
        std::system("cls");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                std::cout << playfield.playfield_matrix[i][j];
            }
            std::cout << std::endl;
        }



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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            piece.rotate_right();
 
            window.clear();
            if (!playfield.correctPos(piece))
            {
                piece.rotate_left();
            }
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);

            //window.display();

            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            piece.rotate_left();
            if (!playfield.correctPos(piece))
            {
                piece.rotate_right();
            }
            window.clear();
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);
            break;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            piece.moveRight();
            if (!playfield.correctPos(piece))
            {
                piece.moveLeft();
            }
            window.clear();
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);
            break;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            piece.moveLeft();
            if (!playfield.correctPos(piece))
            {
                piece.moveRight();
            }
            window.clear();
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);
            break;
        }
        
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500 - clock.getElapsedTime().asMilliseconds()));

        piece.moveDown();
        if (!playfield.correctPos(piece))
        {
            piece.moveUp();            
            playfield.updateMatrix(piece);
            piece = game.getNewTetromino();
        }
        window.display();


    }



    return 0;
}
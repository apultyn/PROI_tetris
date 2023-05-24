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

    //sf::Window::setFramerateLimit(30);
    window.setFramerateLimit(30);


    // Piece generator needed

    
    Game game;
    Tetromino piece = game.getNewTetromino();

    sf::Clock clock;


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


        //sf::Clock clock;
        // have to change waiting time
        // maybe move it to another class?
        
        if (event.type == sf::Event::KeyPressed)
        {

            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                piece.moveLeft();
                if (!playfield.correctPos(piece))
                {
                    piece.moveRight();
                }
                break;

            case sf::Keyboard::Right:
                piece.moveRight();
                if (!playfield.correctPos(piece))
                {
                    piece.moveLeft();
                }
                break;
            case sf::Keyboard::Up:
                piece.rotate_right();
                if (!playfield.correctPos(piece))
                {
                    piece.rotate_left();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                break;
            case sf::Keyboard::Down:
                piece.moveDown();
                if (!playfield.correctPos(piece))
                {
                    piece.moveUp();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
                break;
            default:
                break;

            }
            //window.clear();
            game.drawPlayfield(playfield, window); // prints the matrix
            game.drawTetromino(piece, window);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        //window.clear();
        //game.drawPlayfield(playfield, window); // prints the matrix
        //game.drawTetromino(piece, window);
       
         



        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        //{
        //    piece.rotate_right();
 
        //    window.clear();
        //    if (!playfield.correctPos(piece))
        //    {
        //        piece.rotate_left();
        //    }
        //    game.drawPlayfield(playfield, window); // prints the matrix
        //    game.drawTetromino(piece, window);

        //    //window.display();

        //    break;
        //}
        //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        //{
        //    piece.rotate_left();
        //    if (!playfield.correctPos(piece))
        //    {
        //        piece.rotate_right();
        //    }
        //    window.clear();
        //    game.drawPlayfield(playfield, window); // prints the matrix
        //    game.drawTetromino(piece, window);
        //    break;

        //}
        //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        //{
        //    piece.moveRight();
        //    if (!playfield.correctPos(piece))
        //    {
        //        piece.moveLeft();
        //    }
        //    window.clear();
        //    game.drawPlayfield(playfield, window); // prints the matrix
        //    game.drawTetromino(piece, window);
        //    break;

        //}
        //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        //{
        //    piece.moveLeft();
        //    if (!playfield.correctPos(piece))
        //    {
        //        piece.moveRight();
        //    }
        //    window.clear();
        //    game.drawPlayfield(playfield, window); // prints the matrix
        //    game.drawTetromino(piece, window);
        //    break;
        //}
        //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        //{
        //    while (playfield.correctPos(piece))
        //    {
        //        piece.moveDown();
        //    }
        //    if (!playfield.correctPos(piece))
        //    {
        //        piece.moveUp();
        //    }
        //    window.clear();
        //    game.drawPlayfield(playfield, window); // prints the matrix
        //    game.drawTetromino(piece, window);
        //    break;
        //}
        //
        //}
        //std::this_thread::sleep_for(std::chrono::milliseconds(500 - clock.getElapsedTime().asMilliseconds()));
        if (clock.getElapsedTime().asMilliseconds() >= 500)
        {
            piece.moveDown();
             
            if (!playfield.correctPos(piece))
            {
                piece.moveUp();            
                playfield.updateMatrix(piece);
                piece = game.getNewTetromino();
                std::system("cls");
                for (int i = 0; i < HEIGHT; i++) {                      // prints matrix in terminal
                    for (int j = 0; j < WIDTH; j++) {
                        std::cout << playfield.playfield_matrix[i][j];
                    }
                    std::cout << std::endl;
                }
            }
            clock.restart();
        }

       

        if (playfield.checkGameOver())
        {
            
            window.clear();
            game.drawPlayfield(playfield, window); 
            game.drawTetromino(piece, window);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
        
        window.display();


    }



    return 0;
}
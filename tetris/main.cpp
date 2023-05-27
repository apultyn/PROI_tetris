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

    sf::RenderWindow window(sf::VideoMode(WIDTH * RESIZE * CELL_SIZE * 2, VISIBLE_HEIGHT * RESIZE * CELL_SIZE), "Tetris");
    Playfield playfield;

    window.setFramerateLimit(30);
    
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
        game.drawPlayfield(playfield, window);
        game.drawTetromino(piece, window);
        

        
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
            
            game.drawPlayfield(playfield, window); 
            game.drawTetromino(piece, window);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        
        if (clock.getElapsedTime().asMilliseconds() >= 500)
        {
            piece.moveDown();
             
            if (!playfield.correctPos(piece))
            {
                piece.moveUp();            
                playfield.updateMatrix(piece);
                //window.clear();

                if (playfield.checkIfDelete())
                {
                     playfield.setRowsToDelete();
                     //window.clear();
                     //game.drawPlayfield(playfield, window);
                     
  
                     game.deleteAnimation(playfield.getRowsToDelete(), window, playfield);
                     //game.deleteAnimation(playfield.getRowsToDelete(), window);
                     //window.display();
                     //std::this_thread::sleep_for(std::chrono::milliseconds(1000));


            
                   
              
                     playfield.deleteRows();
                      
                     
                }
                piece = game.getNewTetromino();
            }
            clock.restart();
        }

       

        if (playfield.checkGameOver())
        {
            
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
        window.display();


    }



    return 0;
}
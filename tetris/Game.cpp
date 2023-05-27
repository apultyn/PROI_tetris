#include "Game.h"
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

void Game::drawPlayfield(const Playfield& playfield, sf::RenderWindow& window)
{
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            square.setPosition(j * CELL_SIZE * RESIZE, i * CELL_SIZE * RESIZE);
            square.setOutlineThickness(-1);
            square.setOutlineColor(sf::Color::Black);
            int color = playfield.playfield_matrix[i][j];
            if (color == 1)
            {
                square.setFillColor(sf::Color::Red);

            }
            else if (color == 2)
            {
                square.setFillColor(sf::Color::Blue);
            }
            else if (color == 3)
            {
                square.setFillColor(sf::Color::Yellow);
            }
            else if (color == 4)
            {
                square.setFillColor(sf::Color::Green);
            }
            else if (color == 5)
            {
                square.setFillColor(sf::Color::Magenta);
            }
            else if (color == 0)
            {
                square.setFillColor(sf::Color(57, 61, 71));
            }
            window.draw(square);
        } 
    }
}


void Game::drawTetromino(const Tetromino& piece, sf::RenderWindow& window)
{
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int color = piece.matrix[i][j];
            if (color == 1) {
            square.setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE , (i + piece.getPosY()) * CELL_SIZE * RESIZE);
            square.setOutlineThickness(-1);
            square.setOutlineColor(sf::Color::Black);
            square.setFillColor(sf::Color::Red);  
            window.draw(square);
            }
            else if (color == 2)
            {
                square.setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE, (i + piece.getPosY()) * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color::Blue);
                square.setOutlineThickness(-1);
                square.setOutlineColor(sf::Color::Black);
                window.draw(square);
            }
            else if (color == 3)
            {
                square.setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE, (i + piece.getPosY()) * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color::Yellow);
                square.setOutlineThickness(-1);
                square.setOutlineColor(sf::Color::Black);
                window.draw(square);
            }
            else if (color == 4)
            {
                square.setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE, (i + piece.getPosY()) * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color::Green);
                square.setOutlineThickness(-1);
                square.setOutlineColor(sf::Color::Black);
                window.draw(square);
            }
            else if (color == 5)
            {
                square.setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE, (i + piece.getPosY()) * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color::Magenta);
                square.setOutlineThickness(-1);
                square.setOutlineColor(sf::Color::Black);
                window.draw(square);
            }
           
        }
   
}

Tetromino Game::getNewTetromino()
{
    std::srand(time(0));
    int type = std::rand() % 7 + 1;
    Tetromino tetromino(type);
    int color = std::rand() % 5 + 1;
    tetromino.setColor(color);
    return tetromino;
}

void Game::deleteAnimation(const std::vector<int>& rows, sf::RenderWindow& window, const Playfield& playfield)
{

    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    square.setOutlineThickness(-1);
    square.setOutlineColor(sf::Color::Black);
   
    window.clear();
    drawPlayfield(playfield, window);
         for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row  * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color::White);
                window.draw(square);
                
            }
            

        }
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
 

    window.clear();
    drawPlayfield(playfield, window);
    for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color(57, 61, 71));
                window.draw(square);
            }

        }
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));



    window.clear();
    drawPlayfield(playfield, window);
    for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color::White);
                window.draw(square);
            }

        }

    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    
}
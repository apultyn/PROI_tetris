#include "Game.h"
#include <chrono>
#include <thread>
#include <stdlib.h>

void Game::drawPlayfield(Playfield& playfield, sf::RenderWindow& window)
{
    std::unique_ptr<sf::RectangleShape> square = std::make_unique<sf::RectangleShape>();
    square.get()->setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            square.get()->setPosition(j * CELL_SIZE * RESIZE, i * CELL_SIZE * RESIZE);
            square.get()->setOutlineThickness(-1);
            square.get()->setOutlineColor(sf::Color::Black);
            int color = playfield.playfield_matrix[i][j];
            if (color == 1)
            {
                square.get()->setFillColor(sf::Color::Red);

            }
            else if (color == 2)
            {
                square.get()->setFillColor(sf::Color::Blue);
            }
            else if (color == 3)
            {
                square.get()->setFillColor(sf::Color::Yellow);
            }
            else if (color == 4)
            {
                square.get()->setFillColor(sf::Color::Green);
            }
            else if (color == 5)
            {
                square.get()->setFillColor(sf::Color::Magenta);
            }
            else if (color == 0)
            {
                square.get()->setFillColor(sf::Color(57, 61, 71));
            }
            window.draw(*square);
        } 
    }
}


void Game::drawTetromino(Tetromino& piece, sf::RenderWindow& window)
{
    std::unique_ptr<sf::RectangleShape> square= std::make_unique<sf::RectangleShape>();
    square.get()->setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int color = piece.matrix[i][j];
            if (color == 1) {
            square.get()->setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE , (i + piece.getPosY()) * CELL_SIZE * RESIZE);
            square.get()->setOutlineThickness(-1);
            square.get()->setOutlineColor(sf::Color::Black);
            square.get()->setFillColor(sf::Color::Red);    
            }
            else if (color == 2)
            {
                square.get()->setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE, (i + piece.getPosY()) * CELL_SIZE * RESIZE);
                square.get()->setFillColor(sf::Color::Blue);
                square.get()->setOutlineThickness(-1);
                square.get()->setOutlineColor(sf::Color::Black);
            }
            else if (color == 3)
            {
                square.get()->setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE, (i + piece.getPosY()) * CELL_SIZE * RESIZE);
                square.get()->setFillColor(sf::Color::Yellow);
                square.get()->setOutlineThickness(-1);
                square.get()->setOutlineColor(sf::Color::Black);
            }
            else if (color == 4)
            {
                square.get()->setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE, (i + piece.getPosY()) * CELL_SIZE * RESIZE);
                square.get()->setFillColor(sf::Color::Green);
                square.get()->setOutlineThickness(-1);
                square.get()->setOutlineColor(sf::Color::Black);
            }
            else if (color == 5)
            {
                square.get()->setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE, (i + piece.getPosY()) * CELL_SIZE * RESIZE);
                square.get()->setFillColor(sf::Color::Magenta);
                square.get()->setOutlineThickness(-1);
                square.get()->setOutlineColor(sf::Color::Black);
            }
            window.draw(*square);
           
        }
   
}

Tetromino Game::getNewTetromino()
{
    int type = std::rand() % 7 + 1;
    Tetromino tetromino(type);
    int color = std::rand() % 5 + 1;
    tetromino.setColor(color);
    return tetromino;
}
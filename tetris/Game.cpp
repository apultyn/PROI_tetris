#include "Game.h"
#include <chrono>
#include <thread>


void Game::drawPlayfield(Playfield& playfield, sf::RenderWindow& window)
{
    std::unique_ptr<sf::RectangleShape> square = std::make_unique<sf::RectangleShape>();
    square.get()->setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            square.get()->setPosition(j * CELL_SIZE * RESIZE, i * CELL_SIZE * RESIZE);
            square.get()->setOutlineThickness(-1);
            square.get()->setOutlineColor(sf::Color::Black);
            if (playfield.getPlayfield()[i][j] == 1)
            {
                square.get()->setFillColor(sf::Color::Red);
               
            }
            else
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
            if (piece.matrix[i][j] == 1) {
            square.get()->setPosition(j * CELL_SIZE * RESIZE + piece.getInitX(), i * CELL_SIZE * RESIZE + piece.getInitY());
            square.get()->setOutlineThickness(-1);
            square.get()->setOutlineColor(sf::Color::Black);
            square.get()->setFillColor(sf::Color::Red);    
            }
            window.draw(*square);
           
        }
   
}


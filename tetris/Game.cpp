#include "Game.h"


void Game::drawPlayfield(Playfield& playfield, sf::RenderWindow& window)
{
    sf::RectangleShape square(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            square.setPosition(j * CELL_SIZE * RESIZE, i * CELL_SIZE * RESIZE);
            square.setOutlineThickness(-1);
            square.setOutlineColor(sf::Color::Black);
            if (playfield.getPlayfield()[i][j] == 1)
            {
                square.setFillColor(sf::Color::Red);
               
            }
            else
            {
                square.setFillColor(sf::Color(57, 61, 71));
            }
            window.draw(square);
        } 
    }
}



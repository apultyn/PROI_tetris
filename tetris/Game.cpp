#include "Game.h"
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

void Game::drawPlayfield(const Playfield& playfield) const
{
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    square.setOutlineThickness(-1);
    square.setOutlineColor(sf::Color::Black);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            square.setPosition(j * CELL_SIZE * RESIZE, i * CELL_SIZE * RESIZE);

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
            window->draw(square);
        } 
    }
}


void Game::drawTetromino(const Tetromino& piece) const
{
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE)); 
    square.setOutlineThickness(-1);
    square.setOutlineColor(sf::Color::Black);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int color = piece.matrix[i][j];
            square.setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE , (i + piece.getPosY()) * CELL_SIZE * RESIZE);
            if (color == 1) {
            square.setFillColor(sf::Color::Red);  
            window->draw(square);
            }
            else if (color == 2)
            {
                
                square.setFillColor(sf::Color::Blue);
    
                window->draw(square);
            }
            else if (color == 3)
            {
   
                square.setFillColor(sf::Color::Yellow);

                window->draw(square);
            }
            else if (color == 4)
            {
        
                square.setFillColor(sf::Color::Green);
            
                window->draw(square);
            }
            else if (color == 5)
            {
             
                square.setFillColor(sf::Color::Magenta);
       
                window->draw(square);
            }
           
        }
   
}

Tetromino Game::getNewTetromino() const
{
    std::srand(time(0));
    int type = std::rand() % 7 + 1;
    Tetromino tetromino(type);
    int color = std::rand() % 5 + 1;
    tetromino.setColor(color);
    return tetromino;
}

void Game::deleteAnimation(const std::vector<int>& rows, const Playfield& playfield) const
{

    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    square.setOutlineThickness(-1);
    square.setOutlineColor(sf::Color::Black);
    window->clear();
    drawPlayfield(playfield);
         for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row  * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color::White);
                window->draw(square);
                
            }
            

        }
    window->display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    window->clear();
    drawPlayfield(playfield);
    for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color(57, 61, 71));
                window->draw(square);
            }

        }
    window->display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    window->clear();
    drawPlayfield(playfield);
    for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row * CELL_SIZE * RESIZE);
                square.setFillColor(sf::Color::White);
                window->draw(square);
            }

        }
    window->display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    
}

void Game::setPlayfield(const Playfield& playfield)
{
    this->playfield = playfield;
}

void Game::initWindow()
{
    this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH * RESIZE * CELL_SIZE * 2, VISIBLE_HEIGHT * RESIZE * CELL_SIZE), "Tetris");
}

sf::RenderWindow* Game::getWindow() const
{
    return this->window.get();
}

void Game::startGame()
{
    window->setFramerateLimit(30);
    Tetromino piece = this->getNewTetromino();
    sf::Clock clock;
    sf::Text text;
    sf::Font font;
    font.loadFromFile("Quicklime-Regular.ttf");
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString("YOUR SCORE: " + std::to_string(playfield.getScore()));
    text.setPosition({ 576, 480 });

    while (window->isOpen())
    {

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        this->drawPlayfield(playfield);
        this->drawTetromino(piece);

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

            this->drawPlayfield(playfield);
            this->drawTetromino(piece);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        if (clock.getElapsedTime().asMilliseconds() >= 500)
        {
            piece.moveDown();

            if (!playfield.correctPos(piece))
            {
                piece.moveUp();
                playfield.updateMatrix(piece);

                if (playfield.checkIfDelete())
                {
                    playfield.setRowsToDelete();
                    this->deleteAnimation(playfield.getRowsToDelete(), playfield);
                    playfield.deleteRows();
                    text.setString("YOUR SCORE: " + std::to_string(playfield.getScore()));

                }
                piece = this->getNewTetromino();
            }
            clock.restart();
        }
        window->draw(text);
        if (playfield.checkGameOver())
        {

            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
        window->display();

    }
}
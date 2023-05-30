#include "Game.h"
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>
#include <fstream>

sf::Color getColor(const int& color);

void Game::drawPlayfield(const Playfield& playfield) const
{
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    square.setOutlineThickness(OUTLINE_THICKNESS);
    square.setOutlineColor(sf::Color::Black);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            square.setPosition(j * CELL_SIZE * RESIZE, i * CELL_SIZE * RESIZE);
            int color = playfield.playfield_matrix[i][j];
            sf::Color square_color = getColor(color);
            square.setFillColor(square_color);
            window.getWindow().draw(square);
           
        } 
    }
}


sf::Color getColor(const int& color)
{
    switch (color)
    {
    case GREY:
        return GREY_COLOR;
      
    case SALMON:
        return SALMON_COLOR;
        break;
    case ORANGE:
        return ORANGE_COLOR;
       
    case YELLOW:
        return YELLOW_COLOR;
        
    case GREEN:
        return GREEN_COLOR;
      
    case CYAN:
        return CYAN_COLOR;
       
    case PURPLE:
        return PURPLE_COLOR;
        
    case RED:
        return RED_COLOR;
      
    case DARK_ORANGE:
        return DARK_ORANGE_COLOR;
      
    case SANDY_BROWN:
        return SANDY_BROWN_COLOR;
       
    case DARK_GREEN:
        return DARK_GREEN_COLOR;
        
    case BLUE:
        return BLUE_COLOR;
      
    case DARK_PURPLE:
        return DARK_PURPLE_COLOR;
       
    case NAVY:
        return NAVY_COLOR;
        
    case DARK_MEDIUM_BLUE:
        return DARK_MEDIUM_BLUE_COLOR;
     
    }
    

}

void Game::drawTetromino(const Tetromino& piece) const
{
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE)); 
    square.setOutlineThickness(OUTLINE_THICKNESS);
    square.setOutlineColor(sf::Color::Black);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int color = piece.matrix[i][j];

            square.setPosition((j + piece.getPosX()) * CELL_SIZE * RESIZE , (i + piece.getPosY()) * CELL_SIZE * RESIZE);
            sf::Color square_color = getColor(color);
            square.setFillColor(square_color);
            if(color != GREY)
                window.getWindow().draw(square);
     
        }
   
}

Tetromino Game::getNewTetromino() const
{
    std::srand(time(0));
    int type = std::rand() % 7 + 1;
    Tetromino tetromino(type);
    int color = std::rand() % 14 + 1;
    tetromino.setColor(color);
    return tetromino;
}

void Game::deleteAnimation(const std::vector<int>& rows, const Playfield& playfield) const
{

    sf::RectangleShape square;
    square.setSize(sf::Vector2f(CELL_SIZE * RESIZE, CELL_SIZE * RESIZE));
    square.setOutlineThickness(OUTLINE_THICKNESS);
    square.setOutlineColor(sf::Color::Black);
    square.setFillColor(sf::Color::White);
    window.getWindow().clear();
    drawPlayfield(playfield);
         for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row  * CELL_SIZE * RESIZE);
                window.getWindow().draw(square);
                
            }
            

        }
    window.getWindow().display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    window.getWindow().clear();
    drawPlayfield(playfield);
    square.setFillColor(GREY_COLOR);
    for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row * CELL_SIZE * RESIZE);
                window.getWindow().draw(square);
            }

        }
    window.getWindow().display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    window.getWindow().clear();
    drawPlayfield(playfield); 
    square.setFillColor(sf::Color::White);
    for (int row : rows)
        {

            for (int j = 0; j < WIDTH; j++)
            {
                square.setPosition(j * CELL_SIZE * RESIZE, row * CELL_SIZE * RESIZE);
                window.getWindow().draw(square);
            }

        }
   window.getWindow().display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    
}

void Game::setPlayfield(const Playfield& playfield)
{
    this->playfield = playfield;
}

void Game::startGame()
{
    theme.play();
    window.getWindow().setFramerateLimit(30);
    Tetromino piece = getNewTetromino();
    sf::Clock clock;
    sf::Text text;
    sf::Font font;
    font.loadFromFile("Quicklime-Regular.ttf");
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString("YOUR SCORE: " + std::to_string(playfield.getScore()));
    text.setPosition({ 576, 480 });

    while (window.getWindow().isOpen())
    {

        sf::Event event;
        while (window.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.getWindow().close();
        }
        window.getWindow().clear();
        drawPlayfield(playfield);
        drawTetromino(piece);

        if (event.type == sf::Event::KeyPressed)
        {
            if (clock.getElapsedTime().asMilliseconds() < wait_time)
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
                        if (piece.getPosY() < 0)
                        {
                            piece.rotate_left();
                        }
                        else if (piece.getPosX() < 0)
                        {
                            piece.moveRight();
                            if (!playfield.correctPos(piece))
                            {
                                piece.moveRight();
                                if (!playfield.correctPos(piece))
                                {
                                    piece.moveLeft();
                                    piece.moveLeft();
                                    piece.rotate_left();
                                }
                            }
                        }
                        else if (piece.getPosX() > 6)
                        {
                            piece.moveLeft();
                            if (!playfield.correctPos(piece))
                            {
                                piece.moveLeft();
                                if (!playfield.correctPos(piece))
                                {
                                    piece.moveRight();
                                    piece.moveRight();
                                    piece.rotate_left();
                                }
                            }
                        }
                        else
                        {
                            piece.rotate_left();
                        }
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
                drawPlayfield(playfield);
                drawTetromino(piece);
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
        }

        if (clock.getElapsedTime().asMilliseconds() >= wait_time)
        {
            piece.moveDown();

            if (!playfield.correctPos(piece))
            {
                piece.moveUp();
                playfield.updateMatrix(piece);

                if (playfield.checkIfDelete())
                {
                    playfield.setRowsToDelete();
                    clear.play();
                    deleteAnimation(playfield.getRowsToDelete(), playfield);
                    playfield.deleteRows();
                    text.setString("YOUR SCORE: " + std::to_string(playfield.getScore()));

                }
                piece = getNewTetromino();
            }
            clock.restart();
        }
        window.getWindow().draw(text);
        if (playfield.checkGameOver())
        {
            theme.stop();
            game_over.play();
            std::ifstream inputFile("highscore.txt");
            int highscore_easy, highscore_medium, highscore_hard;
            if (inputFile.is_open())
            {
                inputFile >> highscore_easy;
                inputFile >> highscore_medium;
                inputFile >> highscore_hard;
                inputFile.close();
            }
            if (wait_time == EASY)
            {
                if (playfield.getScore() > highscore_easy)
                {
                    highscore_easy = playfield.getScore();
                }
            }
            else if (wait_time == MEDIUM)
            {
                if (playfield.getScore() > highscore_medium)
                {
                    highscore_medium = playfield.getScore();
                }
            }
            else if (wait_time == HARD)
            {
                if (playfield.getScore() > highscore_hard)
                {
                    highscore_hard = playfield.getScore();
                }
            }
            std::ofstream outputFile("highscore.txt");
            if (outputFile.is_open())
            {
                outputFile << highscore_easy << std::endl;
                outputFile << highscore_medium << std::endl;
                outputFile << highscore_hard << std::endl;
                outputFile.close();
            }
            std::this_thread::sleep_for(std::chrono::seconds(5));
            window.getWindow().close();
        }
        window.getWindow().display();

    }
}

Game::Game(Window& windowRef, int wait_time) : window(windowRef), wait_time(wait_time) 
{
    clear_buf.loadFromFile("Sounds/clear.wav");
    game_over_buf.loadFromFile("Sounds/game-over.wav");
    theme_buf.loadFromFile("Sounds/tetris-theme.wav");
    clear.setBuffer(clear_buf);
    game_over.setBuffer(game_over_buf);
    theme.setBuffer(theme_buf);
    theme.setLoop(true);
    theme.setVolume(50);
};

int Game::getWaitTime()
{
    return this->wait_time;
}
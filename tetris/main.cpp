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

    Game game;
    Playfield playfield;
    sf::RenderWindow window(sf::VideoMode(WIDTH * RESIZE * CELL_SIZE * 2, VISIBLE_HEIGHT * RESIZE * CELL_SIZE), "Tetris");
    sf::Clock clock;        
    sf::Event event; 
    sf::Text text;
    sf::Font font;
    font.loadFromFile("Quicklime-Regular.ttf");
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString("TETRIS");
    text.setCharacterSize(120);
    text.setPosition({275, 100});
    text.setLetterSpacing(2);

    sf::FloatRect ret = text.getGlobalBounds();
    sf::RectangleShape rect;
    rect.setPosition(ret.left - 20, ret.top - 20);
    rect.setSize({ret.width + 40, ret.height + 40});
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(2);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (ret.contains(localPosition.x, localPosition.y)))
        {
            
            text.setScale(0.8, 0.8);
            rect.setScale(0.8, 0.8);
            rect.setPosition(rect.getPosition().x * 1.1, rect.getPosition().y * 0.9);
            text.setPosition(text.getPosition().x * 1.1, text.getPosition().y * 0.9); 
            window.draw(rect);
            window.draw(text);
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); 
            //ext.setCharacterSize(120);
            text.setPosition({ 275, 100 });
            //text.setLetterSpacing(2);

            rect.setPosition(ret.left - 20, ret.top - 20);
            //rect.setSize({ ret.width + 40, ret.height + 40 });
            text.setScale(1, 1);
            rect.setScale(1, 1);
            
            window.draw(rect);
            window.draw(text);
            window.display();
       
            std::this_thread::sleep_for(std::chrono::milliseconds(500));    
            game.initWindow();
            window.close();
            game.startGame();
           
        }

        window.draw(rect);
        window.draw(text);
        window.display();
    }


    return 0;
}
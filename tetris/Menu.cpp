#include "Menu.h"
#include <chrono>
#include <thread>

void setFont(sf::Font& font);
void setText(const std::string& string, sf::Font& font, sf::Text& text);
void decreaseBounds(sf::FloatRect& bounds);
void setRectangle(const sf::FloatRect& bounds, sf::RectangleShape& shape);
void transformText(sf::Text& text, sf::RectangleShape& shape);

Menu::Menu(Window& window) : window(window) 
{
    menu_sound.openFromFile("Sounds/menu-theme.wav");
    menu_sound.setLoop(true);
    menu_sound.setVolume(50);
};

void Menu::openMenu()
{
    menu_sound.play();

    setFont(font);
    setText("EASY", font, easy);
    setText("MEDIUM", font, medium);
    setText("HARD", font, hard);
 

    sf::FloatRect easy_bounds = easy.getGlobalBounds();
    sf::FloatRect medium_bounds = medium.getGlobalBounds();
    sf::FloatRect hard_bounds = hard.getGlobalBounds();

    decreaseBounds(easy_bounds);
    decreaseBounds(medium_bounds);
    decreaseBounds(hard_bounds);

    setRectangle(easy_bounds, easy_rect);
    setRectangle(medium_bounds, medium_rect);
    setRectangle(hard_bounds, hard_rect);

    sf::Texture texture;
    texture.loadFromFile("image.png");
    sf::Sprite sprite;
    sf::Sprite sprite_1;


    sprite.setTexture(texture);
    sprite.setScale(0.4, 0.4);
    sprite_1.setTexture(texture);
    sprite_1.setScale(0.4, 0.4);
    sprite.setPosition(550, 550);
    sprite_1.setRotation(180);
    sprite_1.setPosition(420, 420);

    setText("TETRIS", font, tetris);


    while (window.getWindow().isOpen())
    {
        while (window.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.getWindow().close();
        }
        window.getWindow().clear();
        sf::Vector2i localPosition = sf::Mouse::getPosition(window.getWindow());
        setText("TETRIS", font, tetris);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (easy_bounds.contains(localPosition.x, localPosition.y)))
        {
            transformText(easy, easy_rect);
            window.getWindow().draw(sprite);
            window.getWindow().draw(sprite_1);
            drawAll();
            window.getWindow().display();
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            setText("EASY", font, easy);
            setRectangle(easy_bounds, easy_rect);
            easy.setScale(1, 1);
            easy_rect.setScale(1, 1);
            drawAll();
            window.getWindow().display();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            Game game(window, EASY);
            menu_sound.stop();
            game.startGame();
            

        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (medium_bounds.contains(localPosition.x, localPosition.y)))
        {
            transformText(medium, medium_rect);
            window.getWindow().draw(sprite);
            window.getWindow().draw(sprite_1);  
            drawAll();
            window.getWindow().display();
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            setText("MEDIUM", font, medium);
            setRectangle(medium_bounds, medium_rect);
            medium.setScale(1, 1);
            medium_rect.setScale(1, 1);
            window.getWindow().display();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            Game game(window, MEDIUM);
            menu_sound.stop();
            game.startGame();
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (hard_bounds.contains(localPosition.x, localPosition.y)))
        {
            transformText(hard, hard_rect);
            window.getWindow().draw(sprite);
            window.getWindow().draw(sprite_1);
            drawAll();
            
            window.getWindow().display();
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            setText("HARD", font, medium);
            setRectangle(hard_bounds, hard_rect);
            medium.setScale(1, 1);
            medium_rect.setScale(1, 1);
            window.getWindow().display();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            Game game(window, HARD);
            menu_sound.stop();
            game.startGame();
        }
        window.getWindow().draw(sprite);
        window.getWindow().draw(sprite_1);
        drawAll();
      
        window.getWindow().display();
    }
}

void transformText(sf::Text& text, sf::RectangleShape& shape)
{
    text.setScale(0.8, 0.8);
    shape.setScale(0.8, 0.8);
    shape.setPosition(shape.getPosition().x * 1.1, shape.getPosition().y * 0.9);
    text.setPosition(text.getPosition().x * 1.1, text.getPosition().y * 0.9);
}

void setFont(sf::Font& font)
{
    font.loadFromFile("Quicklime-Regular.ttf");
}

void setText(const std::string& string, sf::Font& font, sf::Text& text)
{
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(120);
    text.setLetterSpacing(2);
    if (string == "EASY")
        text.setPosition(275, 300);
    else if (string == "MEDIUM")
        text.setPosition(200, 500);
    else if (string == "HARD")
        text.setPosition(275, 700);
    else
        text.setPosition(225, 150);
}

void decreaseBounds(sf::FloatRect& bounds)
{
    bounds.left -= 20;
    bounds.top -= 20;
}

void setRectangle(const sf::FloatRect& bounds, sf::RectangleShape& shape)
{
    shape.setPosition(bounds.left, bounds.top);
    shape.setSize({ bounds.width + 40, bounds.height + 40 });
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2);
}

void Menu::drawAll()
{
    window.getWindow().draw(easy_rect);
    window.getWindow().draw(easy);
    window.getWindow().draw(medium_rect);
    window.getWindow().draw(medium);
    window.getWindow().draw(hard_rect);
    window.getWindow().draw(tetris);
    window.getWindow().draw(hard);
}

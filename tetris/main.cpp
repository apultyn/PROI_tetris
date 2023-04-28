#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(10.0f, 20.0f));
    rec.setFillColor(sf::Color::Cyan);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(rec);
        window.display();

    }

    return 0;
}
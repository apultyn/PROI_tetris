#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Window {
private:
    sf::RenderWindow window;

public:
    Window();

    sf::RenderWindow& getWindow();
};
#pragma once
#include "Window.h"
#include <SFML/Graphics.hpp>
#include "Game.h"

class Menu
{
private:
	Window& window;
	sf::Event event;
	sf::Font font;
	sf::Text easy;
	sf::Text medium;
	sf::Text hard;
	sf::Text tetris;
	sf::RectangleShape easy_rect;
	sf::RectangleShape medium_rect;
	sf::RectangleShape hard_rect;
	sf::FloatRect easy_bounds = easy.getGlobalBounds();
	sf::FloatRect medium_bounds = medium.getGlobalBounds();
	sf::FloatRect hard_bounds = hard.getGlobalBounds();
public:
	Menu(Window& window);
	void openMenu();
	void drawAll();
};


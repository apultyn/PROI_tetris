#pragma once
#include "playfield.h"
#include "playfield_dimensions.h"
#include <SFML/Graphics.hpp>
#include "Tetromino.h"


class Game
{
public:
	void drawTetromino(const Tetromino&, sf::RenderWindow& window);
	void drawPlayfield(const Playfield&, sf::RenderWindow& window);
	Tetromino getNewTetromino();
	void deleteAnimation(const std::vector<int>&, sf::RenderWindow& window, const Playfield&);
	//void initWindow();
private:
	enum {BLUE, GREEN, YELLOW, BEER, SALMON} colors;
};


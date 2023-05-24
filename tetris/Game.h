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
	//void initWindow();
private:
	enum {BLUE, GREEN, YELLOW, BEER, SALMON} colors;

};


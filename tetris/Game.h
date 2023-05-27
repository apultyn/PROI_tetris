#pragma once
#include "playfield.h"
#include "playfield_dimensions.h"
#include <SFML/Graphics.hpp>
#include "Tetromino.h"
#include <memory>

class Game
{
public:
	void drawTetromino(const Tetromino&);
	void drawPlayfield(const Playfield&);
	Tetromino getNewTetromino();
	void deleteAnimation(const std::vector<int>&, const Playfield&);
	void initWindow();
	void setPlayfield(const Playfield&);
	void startGame();
	sf::RenderWindow* getWindow();
private:
	enum {BLUE, GREEN, YELLOW, BEER, SALMON} colors;
	Playfield playfield;
	std::unique_ptr<sf::RenderWindow> window;
};


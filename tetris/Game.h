#pragma once
#include "playfield.h"
#include "playfield_dimensions.h"
#include <SFML/Graphics.hpp>
#include "Tetromino.h"
#include <memory>

class Game
{
public:
	void drawTetromino(const Tetromino&) const;
	void drawPlayfield(const Playfield&) const;
	Tetromino getNewTetromino() const;
	void deleteAnimation(const std::vector<int>&, const Playfield&) const;
	void initWindow();
	void setPlayfield(const Playfield&);
	void startGame();
	sf::RenderWindow* getWindow() const;
private:
/*	enum {BLUE, GREEN, YELLOW, BEER, SALMON} colors*/;
	Playfield playfield;
	std::unique_ptr<sf::RenderWindow> window;
};


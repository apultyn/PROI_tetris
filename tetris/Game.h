#pragma once
#include "playfield.h"
#include "playfield_dimensions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tetromino.h"
#include "Window.h"

class Game
{
public:
	void drawTetromino(const Tetromino&) const;
	void drawPlayfield(const Playfield&) const;
	Tetromino getNewTetromino() const;
	void deleteAnimation(const std::vector<int>&, const Playfield&) const;
	void setPlayfield(const Playfield&);
	void startGame();
	Game(Window& window, int wait_time=500);;
	int getWaitTime();
	void printEnd(int& score);
private:
	Playfield playfield;
	Window& window;
	int wait_time;
	sf::Music theme;
	sf::Music clear;
	sf::Music game_over;
};


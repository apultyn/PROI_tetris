#pragma once
#include "playfield.h"
#include "playfield_dimensions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tetromino.h"
#include <memory>
#include "Window.h"

class Game
{
public:
	sf::Sound clear;
	sf::Sound game_over;
	sf::Sound theme;
	void drawTetromino(const Tetromino&) const;
	void drawPlayfield(const Playfield&) const;
	Tetromino getNewTetromino() const;
	void deleteAnimation(const std::vector<int>&, const Playfield&) const;
	//void initWindow();
	void setPlayfield(const Playfield&);
	void startGame();
	Game(Window& window, int wait_time=500);;
	int getWaitTime();
	//sf::RenderWindow* getWindow() const;
private:
	Playfield playfield;
	//std::unique_ptr<sf::RenderWindow> window;
	Window& window;
	int wait_time;
	sf::SoundBuffer clear_buf;
	sf::SoundBuffer game_over_buf;
	sf::SoundBuffer theme_buf;
};


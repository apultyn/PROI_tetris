#pragma once
#include "playfield.h"
#include "playfield_dimensions.h"
#include <SFML/Graphics.hpp>
#include "Tetrominoes.h"


class Game
{
public:
	//void drawTetrominoe(Tetrominoes&);
	void drawPlayfield(Playfield&, sf::RenderWindow& window);
	//void initWindow();
};


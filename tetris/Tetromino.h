#pragma once
#include "playfield_dimensions.h"
#include <vector>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>


class Tetromino
{
private:
	int posX = 3;
	int posY = -2;
public:
	int matrix[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	Tetromino(const char type);
	Tetromino(const char type, int posx, int posy);
	void rotate_left();
	void rotate_right();
	//void updateMatrix(std::vector<std::vector<int>>&);
	void transpose_matrix();
	std::string toString();
	int getInitX();
	int getInitY();
	int getPosX() const;
	int getPosY() const;
	void moveDown();
	void moveRight();
	void moveLeft();
	void moveUp();
	void setColor(const unsigned short value);
};


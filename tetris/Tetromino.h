#pragma once
#include "playfield_dimensions.h"
#include <vector>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>


class Tetromino
{
private:
	int initX = CELL_SIZE * RESIZE * 3;
	int initY = - CELL_SIZE * RESIZE * 4;
	int posX = 0;
	int posY = 0;
public:
	int matrix[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	Tetromino(const char type);
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
	void setColor(const unsigned short value);
};


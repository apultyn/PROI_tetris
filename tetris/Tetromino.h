#pragma once
#include "playfield_dimensions.h"
#include <vector>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>


class Tetromino
{
private:
	//int initX = CELL_SIZE * RESIZE * 3;
	//int initY = - CELL_SIZE * RESIZE * 4;
	int posX = 3;
	int posY = -2;
public:
	char matrix[4][4] = {
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
	void setColor(const char value);
};


#pragma once
#include "playfield_dimensions.h"
#include <vector>
#include <string>
#include <sstream>

class Tetromino
{
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
};

#pragma once
#include "playfield_dimensions.h"
#include <vector>
#include <string>

class Tetromino
{
private:
	std::vector<std::vector<int>> matrix;
public:
	Tetromino(const char& type);
	std::vector<std::vector<int>> get_matrix() const;
	//void rotate_left();
	//void rotate_right();
	void updateMatrix(std::vector<std::vector<int>>&);
	void transpose_matrix();
};

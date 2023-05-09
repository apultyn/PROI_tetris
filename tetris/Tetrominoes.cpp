#include "Tetrominoes.h"

void Tetromino::updateMatrix(std::vector<std::vector<int>>& playfield_matrix)
{
    // just test
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->get_matrix()[i][j] != 0) { // if the square in the piece is not empty
                playfield_matrix[i][j] = this->get_matrix()[i][j]; // copy the value of the piece square to the corresponding location in the game board
            }
        }
    }
}

std::vector<std::vector<int>> Tetromino::get_matrix() const {
	return this->matrix;
}

Tetromino::Tetromino(const char& type) {
	if (type == 'I') {
		this->matrix = {
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
	}
	else if (type == 'J') {
		this->matrix = {
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
	}
	else if (type == 'L') {
		this->matrix = {
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
	}
	else if (type == 'O') {
		this->matrix = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		};
	}
	else if (type == 'S') {
		this->matrix = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		};
	}
	else if (type == 'T') {
		this->matrix = {
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		};
	}
	else if (type == 'Z') {
		this->matrix = {
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		};
	}
};

void Tetromino::transpose_matrix() {
	std::vector<std::vector<int>> new_matrix;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			new_matrix[i][j] = this->get_matrix()[j][i];
		}
	}
	this->matrix = new_matrix;
}

std::string Tetromino::toString() {
	std::stringstream tostring;
	tostring << '[';
	for (const auto& row : this->get_matrix()) {
		for (const auto& val : row) {
			tostring << val << ',';
		}
	}
	tostring << ']';
	return tostring.str();
}
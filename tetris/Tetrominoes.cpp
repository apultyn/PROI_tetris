#include "Tetrominoes.h"

//void Tetromino::updateMatrix(std::vector<std::vector<int>>& playfield_matrix)
//{
//    // just test
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            if (this->get_matrix()[i][j] != 0) { // if the square in the piece is not empty
//                playfield_matrix[i][j] = this->get_matrix()[i][j]; // copy the value of the piece square to the corresponding location in the game board
//            }
//        }
//    }
//}

Tetromino::Tetromino(const char type) {
	if (type == 'I') {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 'J') {
		int temp[4][4] = {
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 'L') {
		int temp[4][4] = {
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 'O') {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 'S') {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 'T') {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 'Z') {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
};

void Tetromino::transpose_matrix() {
	int new_matrix[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			new_matrix[i][j] = this->matrix[j][i];
		}
	}
	memcpy(this->matrix, new_matrix, sizeof(this->matrix));
};

void Tetromino::rotate_right() {
	this->transpose_matrix();
	int new_matrix[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			new_matrix[i][j] = this->matrix[i][3 - j];
		}
	}
	memcpy(this->matrix, new_matrix, sizeof(this->matrix));
}

void Tetromino::rotate_left() {
	this->transpose_matrix();
	int new_matrix[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			new_matrix[i][j] = this->matrix[3 - i][j];
		}
	}
	memcpy(this->matrix, new_matrix, sizeof(this->matrix));
}

std::string Tetromino::toString() {
	std::stringstream tostring;
	tostring << '[';
	for (const auto& row : this->matrix) {
		for (const auto& val : row) {
			tostring << val << ',';
		}
	}
	tostring << ']';
	return tostring.str();
}
#include "Tetromino.h"


Tetromino::Tetromino(const char type) {
	if (type == 1) {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 2) {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 3) {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 4) {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 5) {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 6) {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 7) {
		int temp[4][4] = {
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
};

Tetromino::Tetromino(const char type, int posx, int posy) : Tetromino(type) {
	this->posX = posx;
	this->posY = posy;
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


void Tetromino::moveDown()
{
	posY += 1;
}

void Tetromino::moveRight()
{
	posX += 1;
}

void Tetromino::moveLeft()
{
	posX -= 1;
}

void Tetromino::moveUp()
{
	posY -= 1;
}

int Tetromino::getPosX() const {
	return posX;
}

int Tetromino::getPosY() const {
	return posY;
}

void Tetromino::setColor(const unsigned short value) 
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (this->matrix[i][j] != 0) {
				this->matrix[i][j] = value;
			}
		}
	}
}
#include "Tetromino.h"


Tetromino::Tetromino(const char type) {
	if (type == 1) {
		int temp[TETROMINO_SIZE][TETROMINO_SIZE] = {
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 2) {
		int temp[TETROMINO_SIZE][TETROMINO_SIZE] = {
			{0, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 3) {
		int temp[TETROMINO_SIZE][TETROMINO_SIZE] = {
			{0, 0, 0, 0},
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == TETROMINO_SIZE) {
		int temp[TETROMINO_SIZE][TETROMINO_SIZE] = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 5) {
		int temp[TETROMINO_SIZE][TETROMINO_SIZE] = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 6) {
		int temp[TETROMINO_SIZE][TETROMINO_SIZE] = {
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		};
		memcpy(this->matrix, temp, sizeof(this->matrix));
	}
	else if (type == 7) {
		int temp[TETROMINO_SIZE][TETROMINO_SIZE] = {
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
	int new_matrix[TETROMINO_SIZE][TETROMINO_SIZE];
	for (int i = 0; i < TETROMINO_SIZE; i++) {
		for (int j = 0; j < TETROMINO_SIZE; j++) {
			new_matrix[i][j] = this->matrix[j][i];
		}
	}
	memcpy(this->matrix, new_matrix, sizeof(this->matrix));
};

void Tetromino::rotate_right() {
	this->transpose_matrix();
	int new_matrix[TETROMINO_SIZE][TETROMINO_SIZE];
	for (int i = 0; i < TETROMINO_SIZE; i++) {
		for (int j = 0; j < TETROMINO_SIZE; j++) {
			new_matrix[i][j] = this->matrix[i][3 - j];
		}
	}
	memcpy(this->matrix, new_matrix, sizeof(this->matrix));
}

void Tetromino::rotate_left() {
	this->transpose_matrix();
	int new_matrix[TETROMINO_SIZE][TETROMINO_SIZE];
	for (int i = 0; i < TETROMINO_SIZE; i++) {
		for (int j = 0; j < TETROMINO_SIZE; j++) {
			new_matrix[i][j] = this->matrix[3 - i][j];
		}
	}
	memcpy(this->matrix, new_matrix, sizeof(this->matrix));
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
	for (int i = 0; i < TETROMINO_SIZE; i++) {
		for (int j = 0; j < TETROMINO_SIZE; j++) {
			if (this->matrix[i][j] != 0) {
				this->matrix[i][j] = value;
			}
		}
	}
}
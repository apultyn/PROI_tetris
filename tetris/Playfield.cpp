#include "Playfield.h"
#include <algorithm>

bool Playfield::correctPos(const Tetromino& tetromino) 
{
	for (int row = 0; row < 4; row++) 
	{
		for (int column = 0; column < 4; column++) 
		{
			if (tetromino.matrix[row][column] != 0)
			{
				if (row + tetromino.getPosY() < 0 || row + tetromino.getPosY() > 19 || column + tetromino.getPosX() < 0 || column + tetromino.getPosX() > 9)
				{
					return false;
				}
				else if (tetromino.matrix[row][column] != 0 && this->playfield_matrix[row + tetromino.getPosY()][column + tetromino.getPosX()] != 0)
				{
					return false;
				}
			}
		}
	}
	return true;
};

void Playfield::updateMatrix(const Tetromino& tetromino)
{
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			if (tetromino.matrix[row][column] != 0)
			{
				this->playfield_matrix[tetromino.getPosY() + row][tetromino.getPosX() + column] = tetromino.matrix[row][column];
			}
		}
	}
}

bool Playfield::checkGameOver()
{

	for (int column = 0; column < WIDTH; column++)
	{
		if (this->playfield_matrix[0][column] != 0)
		{
			return true;
		}
	}
	return false;
}


bool Playfield::checkIfDelete()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		if (std::all_of(playfield_matrix[i], playfield_matrix[i] + WIDTH, [](int x) { return x != 0; }))
		{
			return true;
		}
	}
	return false;
}

//void Playfield::initPlayfield()
//{
//	for (int i = 0; i < WIDTH; i++)
//		for (int j = 0; j < HEIGHT; j++)
//			playfield_matrix[i][j] = FREE;
//
//}
//
//Playfield::Playfield()
//{
//	this->initPlayfield();
//}







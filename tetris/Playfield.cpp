#include "Playfield.h"

bool Playfield::correctPos(const Tetromino& tetromino) 
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (tetromino.matrix[i][j] != 0 && this->playfield_matrix[i + tetromino.getPosX()][j + tetromino.getPosY()] != 0) 
			{
				return false;
			}
		}
	}
	return true;
};

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







#include "Playfield.h"

bool Playfield::correctPos(const Tetromino& tetromino) 
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (tetromino.matrix[i][j] != 0)
			{
				if (i + tetromino.getPosY() < 0 || i + tetromino.getPosY() > 20 || j + tetromino.getPosX() < 0 || j + tetromino.getPosX() > 10)
				{
					return false;
				}
				else if (tetromino.matrix[i][j] != 0 && this->playfield_matrix[i + tetromino.getPosY()][j + tetromino.getPosX()] != 0)
				{
					return false;
				}
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







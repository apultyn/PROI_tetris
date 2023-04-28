#include "Playfield.h"


void Playfield::initPlayfield()
{
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			playfield_matrix[i][j] = FREE;

}

Playfield::Playfield()
{
	this->initPlayfield();
}






#include "Playfield.h"
#include <algorithm>

bool Playfield::correctPos(const Tetromino& tetromino) const
{
	for (int row = 0; row < TETROMINO_SIZE; row++) 
	{
		for (int column = 0; column < TETROMINO_SIZE; column++) 
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
	for (int row = 0; row < TETROMINO_SIZE; row++)
	{
		for (int column = 0; column < TETROMINO_SIZE; column++)
		{
			if (tetromino.matrix[row][column] != 0)
			{
				this->playfield_matrix[tetromino.getPosY() + row][tetromino.getPosX() + column] = tetromino.matrix[row][column];
			}
		}
	}
}

bool Playfield::checkGameOver() const
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


bool Playfield::checkIfDelete() const
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

void Playfield::setRowsToDelete()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		if (std::all_of(playfield_matrix[i], playfield_matrix[i] + WIDTH, [](int x) { return x != 0; }))
		{
			this->del_rows.push_back(i);
		}
	}
}

void Playfield::deleteRows()
{
	for (int row : this->del_rows)
	{
		for (int i = row; i > 0; i--) {
			
			for (int j = 0; j < WIDTH; j++)
			{
				this->playfield_matrix[i][j] = this->playfield_matrix[i - 1][j];
			}
			
		}
	}

	for (int i = 0; i < this->del_rows.size(); i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			this->playfield_matrix[i][j] = 0;
		}
	}
	this->score += this->del_rows.size() * POINTS;
	this->del_rows.clear();
	

}


std::vector<int> Playfield::getRowsToDelete() const
{
	return this->del_rows;
}

int Playfield::getScore() const
{
	return this->score;
}







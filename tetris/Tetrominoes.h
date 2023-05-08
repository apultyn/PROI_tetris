#pragma once
#include "playfield_dimensions.h"
#include <vector>
class Tetrominoes
{
private:
	// L - piece test
	int piece[4][4] = {
  { 0, 0, 0, 0 },
  { 0, 0, 0, 0 },
  { 0, 1, 1, 1 },
  { 0, 0, 0, 1 }
	};
public:
	void updateMatrix(std::vector<std::vector<int>>&);
	//int getPosX();
	//int getPosY();
};


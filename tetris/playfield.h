#pragma once
#include "playfield_dimensions.h"
#include <vector>

class Playfield
{
private:
	int playfield_matrix[HEIGHT][WIDTH];
	enum field_status {FREE, FILLED};

public:
	Playfield();
	void initPlayfield();



};


#pragma once
#include "playfield_dimensions.h"
#include "Tetromino.h"

class Playfield
{
public:
    char playfield_matrix[HEIGHT][WIDTH];
    Playfield();
    bool correctPos(const Tetromino& tetromino);
    void updateMatrix(const Tetromino& tetromino);
    bool checkGameOver();

    // checking if game is over
    // deleting a line(s)
    // checking if movement is possible
    // color will be represented by numbers 1,2,3...
private:
	//enum field_status {FREE, FILLED};
};


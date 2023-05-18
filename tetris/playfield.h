#pragma once
#include "playfield_dimensions.h"
#include <vector>

class Playfield
{
public:
    int playfield_matrix[HEIGHT][WIDTH] = { 0 };
    Playfield() {
        //int new_matrix[WIDTH][HEIGHT] ;
        //memcpy(this->playfield_matrix, new_matrix, sizeof(this->playfield_matrix));
    }

    // checking if game is over
    // deleting a line(s)
    // checking if movement is possible
    // color will be represented by numbers 1,2,3...
private:
	//enum field_status {FREE, FILLED};
};


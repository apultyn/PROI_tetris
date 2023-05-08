#pragma once
#include "playfield_dimensions.h"
#include <vector>

class Playfield
{
public:
    Playfield() : playfield_matrix(HEIGHT, std::vector<int>(WIDTH, 0)) {}

    std::vector<std::vector<int>>& getPlayfield(){
        return playfield_matrix;
    }
    // checking if game is over
    // deleting a line(s)
    // checking if movement is possible
    // color will be represented by numbers 1,2,3...
private:
    std::vector<std::vector<int>> playfield_matrix;
	//enum field_status {FREE, FILLED};
};


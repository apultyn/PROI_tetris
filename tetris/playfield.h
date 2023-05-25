#pragma once
#include "playfield_dimensions.h"
#include "Tetromino.h"
#include <vector>

class Playfield
{
public:
    int playfield_matrix[HEIGHT][WIDTH] = { 0 };
    Playfield() {};
    bool correctPos(const Tetromino& tetromino);
    void updateMatrix(const Tetromino& tetromino);
    bool checkGameOver();
    bool checkIfDelete();
    void setRowsToDelete();
    void deleteRows();
    std::vector<int> getRowsToDelete();
    int getScore();


    // checking if game is over
    // deleting a line(s)
    // checking if movement is possible
    // color will be represented by numbers 1,2,3...
private:
    std::vector<int> del_rows;
    int score;
	//enum field_status {FREE, FILLED};
};


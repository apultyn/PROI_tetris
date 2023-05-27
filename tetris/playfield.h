#pragma once
#include "playfield_dimensions.h"
#include "Tetromino.h"
#include <vector>

class Playfield
{
public:
    int playfield_matrix[HEIGHT][WIDTH] = { 0 };
    Playfield() {};
    bool correctPos(const Tetromino& tetromino) const;
    void updateMatrix(const Tetromino& tetromino);
    bool checkGameOver() const;
    bool checkIfDelete() const;
    void setRowsToDelete();
    void deleteRows();
    std::vector<int> getRowsToDelete() const;
    int getScore() const;
private:
    std::vector<int> del_rows;
    int score;

};


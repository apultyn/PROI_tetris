#include "Tetrominoes.h"
#include <vector>

void Tetrominoes::updateMatrix(std::vector<std::vector<int>>& playfield_matrix)
{
    // just test
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece[i][j] != 0) { // if the square in the piece is not empty
                playfield_matrix[i][j] = piece[i][j]; // copy the value of the piece square to the corresponding location in the game board
            }
        }
    }
}

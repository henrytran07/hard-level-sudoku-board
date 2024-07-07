#ifndef HARD_SUDO_H
#define HARD_SUDO_H

#include "sudo.h"
#include <iostream>

using namespace std;

class HardSudoku : public Sudoku {
private:
    int** user_board;
    int numbers_of_hint_in_one_row = 3;
    int total_numbers_in_one_matrix = 27; 
public:
    // HardSudoku(int full_board[ROW][COL]);
    HardSudoku();
      
    void user_board_copy();
    bool match();
    ~HardSudoku();

private:
    int generateRandomStep();
    void user_board_display(); 
};

#endif // HARD_SUDO_H

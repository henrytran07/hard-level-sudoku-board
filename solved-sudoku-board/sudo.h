#ifndef SUDO_H
#define SUDO_H

class Sudoku {
protected:
    static const int ROW = 9;   
    static const int COL = 9;  
    int** sudoku;              
    void generateFirstRow();    
    bool isValid(int row, int col, int num); 
    bool solveSudoku();
public:
    Sudoku();                   
    // Sudoku(int sudo[ROW][COL]); 
    ~Sudoku();                  
    void printBoard();         
};

#endif

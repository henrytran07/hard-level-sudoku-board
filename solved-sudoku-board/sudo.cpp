
#include "sudo.h"
#include <iostream> 
#include <vector> 
#include <numeric>
#include <algorithm> 
#include <random> 
using namespace std; 

Sudoku::Sudoku() {
    sudoku = new int*[ROW];
        for (int row = 0; row < ROW; row++){
            sudoku[row] = new int[COL];
            for (int col = 0; col < COL; col++){
                sudoku[row][col] = 0; 
        }
    }
}

// Sudoku::Sudoku(int sudo[ROW][COL]) {
//     sudoku = new int*[ROW];
//     for (int row = 0; row < ROW; row++) {
//         sudoku[row] = new int[COL];
//         for (int col = 0; col < COL; col++) {
//             sudoku[row][col] = sudo[row][col];
//         }
//     }
// }

Sudoku::~Sudoku() {
    for (int i = 0; i < ROW; i++) {
        delete[] sudoku[i];
    }
    delete[] sudoku;
}

void Sudoku::generateFirstRow(){
    vector<int> num(9);
    iota(num.begin(), num.end(), 1);
    random_device rd; 
    mt19937 g(rd());
    shuffle(num.begin(), num.end(), g);
    for (int i = 0; i < COL; i++){
        sudoku[0][i] = num[i];
    }
}

bool Sudoku::isValid(int row, int col, int num){
    for (int i = 0; i < 9; i++){
        if (sudoku[i][col] == num || sudoku[row][i] == num){
            return false; 
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3; 

    for (int row = startRow; row < startRow + 3; row++){
        for (int col = startCol; col < startCol + 3; col++){
            if (sudoku[row][col] == num){
                return false; 
            }
        }
    }
    return true; 
}

bool Sudoku::solveSudoku() {
    generateFirstRow();
    for (int row = 0; row < ROW; row++){
        for (int col = 0; col < COL; col++){
            if (sudoku[row][col] == 0){
                for (int num = 1; num <= 9; num++){
                    if (isValid(row, col, num)){
                        sudoku[row][col] = num; 
                        if (solveSudoku()){
                            return true; 
                        }
                        sudoku[row][col] = 0;
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}

void Sudoku:: printBoard(){
    for (int row = 0; row < ROW; row++){
        for (int col = 0; col < COL; col++){
            cout << sudoku[row][col] << " ";
            //editted by J
            if (col == 2 || col == 5)
                cout << '|';
        }
        cout << endl; 
    }
}

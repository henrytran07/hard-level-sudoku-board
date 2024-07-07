#include "hardsudo.h"
#include <iostream> 
#include <vector> 
#include <numeric> 
#include <algorithm>
#include <random>

using namespace std;

// Default constructor
HardSudoku::HardSudoku() {
    user_board = new int*[ROW];
    for (int row = 0; row < ROW; row++) {
        user_board[row] = new int[COL];
        for (int col = 0; col < COL; col++) {
            user_board[row][col] = 0;
        }
    }
}

// Destructor
HardSudoku::~HardSudoku() {
    for (int i = 0; i < ROW; i++) {
        delete[] user_board[i];
    }
    delete[] user_board;
}

// Private function to generate a random step
int HardSudoku::generateRandomStep() {
    vector<int> num(4);
    iota(num.begin(), num.end(), 1);

    random_device rd; 
    mt19937 g(rd());
    shuffle(num.begin(), num.end(), g);
    return num[0];
}

// Copy user_board from sudoku with hints
void HardSudoku::user_board_copy() {
    solveSudoku();
    int total_given_numbers = 0; 
    for (int row = 0; row < ROW; row++) {
        int colStep = generateRandomStep();
        int hints_in_row = 0;
        for (int col = 0; col < COL; col += colStep) {
            if (hints_in_row < numbers_of_hint_in_one_row && total_given_numbers < total_numbers_in_one_matrix) {
                user_board[row][col] = sudoku[row][col];
                hints_in_row++;
                total_given_numbers++; 
            }
        }
    }
    cout << "Total given numbers: " << total_given_numbers << endl; 
}

// Display user_board
void HardSudoku::user_board_display() {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            cout << user_board[row][col] << " ";
            // Print vertical line after every third column
            if (col % 3 == 2 && col != COL - 1)
                cout << '|';
        }
        cout << endl;

        // Print horizontal line after every third row
        if (row % 3 == 2 && row != ROW - 1) {
            for (int col = 0; col < COL; col++) {
                cout << "__";
                if (col % 3 == 2 && col != COL - 1)
                    cout << "|";
            }
            cout << endl;
        }
    }
}

// Match user input with sudoku solution
bool HardSudoku::match() {
    int user_input; 
    user_board_display();
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (user_board[row][col] == 0) {
                cout << "Please enter the number in " << row << " row, and " << col << " col: ";
                cin >> user_input;
                user_board[row][col] = user_input; 
                user_board_display();
            }
        }
    }

    // Check if user_board matches sudoku
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (user_board[row][col] != sudoku[row][col]) {
                return false; 
            }
        }
    }
    return true; 
}

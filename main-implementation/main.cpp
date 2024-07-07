#include "hardsudo.h"
#include <iostream>
#include "sudo.h"
using namespace std;

int main() {
    HardSudoku hard;
    hard.user_board_copy();
    bool game = hard.match();

    if (game) {
        cout << "Congratulations! You solved the Sudoku puzzle." << endl;
    } else {
        cout << "Sorry, the Sudoku puzzle remains unsolved." << endl;
    }

    return 0;
}

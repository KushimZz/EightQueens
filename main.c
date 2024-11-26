#include <stdio.h>

//8x8 board
int board[8][8] = {0};

// function to check if it's safe to place a queen to the given row and columns
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {  // loop through all previous rows
        if (board[i][col] == 1) {  // check the same column for a queen
            return 0;
        }
        // check the upper left diagonal
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1) {
            return 0;
        }
        // check the upper right diagonal
        if (col + (row - i) < 8 && board[i][col + (row - i)] == 1) {
            return 0;
        }
    }
    return 1;  // if its safe to place the queen, return 1
}
// function to solve the 8 Queens problem starting from the given row
int solve8Queens(int row) {
    if (row == 8) {  // if all queens are placed in 8 rows
        return 1;
    }
    // placing a queen in each column of the current row
    for (int col = 0; col < 8; col++) {
        if (isSafe(row, col)) {  // check if it's safe to place a queen
            board[row][col] = 1;  // place the queen
            if (solve8Queens(row + 1)) {  // try to place the next queen
                return 1;  // if successful return 1
            }
            // if placing the next queen was not successful, backtrack
            board[row][col] = 0;  // backtrack: remove the queen
        }
    }
    return 0;  // no position found in so return 0
}
// function to print the current scenario of the board
void printSolution() {
    for (int i = 0; i < 8; i++) {  // loop through each row
        for (int j = 0; j < 8; j++) {  // loop through each column
            if (board[i][j] == 1) {  // if theres a queen
                printf("Q ");  // print 'Q' for queen
            } else {
                printf("_ ");  // print '_' for empty cell
            }
        }
        printf("\n");  // new line after each row
    }
}
// main
int main() {
    board[0][0] = 1;  // you can change the column of first Queen. Dont change the row because in this program we cant add Queens to above of the first queen's row. this is why i wrote an error code for it.

    // check if a queen is placed in the first row
    int queenFound = 0;
    for (int j = 0; j < 8; j++) {  // loop through each column in the first row
        if (board[0][j] == 1) {  // check if there's a queen
            queenFound = 1;  // if there is a queen in first row set it to 1
            break;
        }
    }
    if (!queenFound) {  // if no queen was found
        printf("Error: No queen placed in the first row.\n");
        return 1;
    }
    // start solving the problem from the second row
    if (solve8Queens(1)) {  // if a solution is found
        printSolution();
    } else {
        printf("No solution found.\n");
    }
    return 0;
}

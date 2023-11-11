// Design n-Queens matrix having first Queen placed. Use backtracking to place 
// remaining Queens to generate the final n-queen 

#include <iostream>

void printSolution(int** board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isSafe(int** board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int** board, int col, int n) {
    if (col >= n) {
        printSolution(board, n);
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1, n) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQueens(int firstQueenRow, int n) {
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n]();
    }
    board[firstQueenRow][0] = 1;
    solveNQueensUtil(board, 1, n);

    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int main() {
    int n = 4;
    int firstQueenRow = 2;

    solveNQueens(firstQueenRow, n);

    return 0;
}

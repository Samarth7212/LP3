#include <iostream>
#include <vector>
using namespace std;

class NQueens
{

public:
    void printBoard(vector<string> &board)
    {
        for (auto &x : board)
            cout << x << endl;
        cout << endl;
    }

    void helper(int col, vector<vector<string>> &ans, int n, vector<bool> &hor, vector<bool> &downdiag, vector<bool> &updiag, vector<string> &board)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            bool isValid = !hor[row] && !downdiag[row + col] && !updiag[n - 1 + col - row];
            if (isValid)
            {
                board[row][col] = 'Q';
                hor[row] = 1;
                downdiag[row + col] = 1;
                updiag[n - 1 + col - row] = 1;
                helper(col + 1, ans, n, hor, downdiag, updiag, board);
                board[row][col] = '.';
                hor[row] = 0;
                downdiag[row + col] = 0;
                updiag[n - 1 + col - row] = 0;
            }
        }
    }

    void solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        vector<bool> hor(n, 0), downdiag(2 * n - 1, 0), updiag(2 * n - 1, 0);

        helper(0, ans, n, hor, downdiag, updiag, board);

        for (auto &x : ans)
        {
            for (auto &y : x)
            {
                for (char &c : y)
                {
                    if (c == '.')
                        cout << "[_]";
                    else
                        cout << "[Q]";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    NQueens obj = NQueens();
    obj.solveNQueens(4);
    return 0;
}
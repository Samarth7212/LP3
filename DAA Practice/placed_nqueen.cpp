#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int r, int c, vector<vector<int>> &board, int n)
{
    // upper left
    int i = r, j = c;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }
    // lower left;
    i = r;
    j = c;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i++;
        j--;
    }
    // left
    i = r;
    j = c;
    while (j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        j--;
    }
    // upperright;
    i = r;
    j = c;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;
        j++;
        i--;
    }

    // lower right;
    i = r;
    j = c;
    while (i < n && j < n)
    {
        if (board[i][j] == 1)
            return false;
        i++;
        j++;
    }
    // right
    i = r;
    j = c;
    while (j < n)
    {
        if (board[i][j] == 1)
            return false;
        j++;
    }
    return true;
}
void solve(int col, int col1, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        for (auto c : board)
        {
            for (auto x : c)
            {
                cout << x;
            }
            cout << endl;
        }
        return;
    }
    if (col == col1)
    {
        solve(col + 1, col1, board, n);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, board, n))
        {
            board[i][col] = 1;
            solve(col + 1, col1, board, n);
            board[i][col] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int r, c;
    cin >> r >> c;
    board[r][c] = 1;
    solve(0, c, board, n);
}
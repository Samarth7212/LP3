#include <iostream>
#include <vector>

using namespace std;

int helper(int ind, int n, int w, vector<int> &profits, vector<int> &weights, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][w] != -1)
        return dp[ind][w];
    if (weights[ind] > w)
        return dp[ind][w] = helper(ind + 1, n, w, profits, weights, dp);
    else
        return dp[ind][w] = max(
                   profits[ind] + helper(ind + 1, n, w - weights[ind], profits, weights, dp),
                   helper(ind + 1, n, w, profits, weights, dp));
}

int knapSack(int w, vector<int> &profits, vector<int> &weights)
{
    int n = profits.size();
    vector<vector<int>> dp(n + 2, vector<int>(100, -1));

    return helper(0, n, w, profits, weights, dp);
}

int main()
{

    vector<int> profit = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int n = 3;

    cout << knapSack(50, profit, weights);

    return 0;
}
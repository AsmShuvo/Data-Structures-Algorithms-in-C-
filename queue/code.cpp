#include <bits/stdc++.h>
using namespace std;

// memorization
int memo[100][100];
int knapsack(int W, vector<int> &wt, vector<int> &cost, int n)
{
    if (W == 0 || n == 0)
        return 0;
    if (memo[n][W])
        return memo[n][W];
    if (wt[n - 1] > W)
    {
        // dont take this
        return memo[n][W] = knapsack(W, wt, cost, n - 1);
    }
    else
    {
        // take best one
        int ans = max(knapsack(W, wt, cost, n - 1), cost[n - 1] + knapsack(W - wt[n - 1], wt, cost, n - 1));
        memo[n][W] = ans;
        return ans;
    }
}

int knapsackTabulation(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || 0 == w)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> wt = {2, 3, 2, 4}, cost = {10, 11, 5, 7};
    int W = 8;
    int n = cost.size();
    cout << knapsack(W, wt, cost, n) << endl;
    cout << knapsackTabulation(W, wt, cost, n) << endl;
}
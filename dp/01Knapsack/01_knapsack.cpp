#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// Topic: 0-1 Knapsack Problem
// ==========================================

// 1. Recursive Solution
// Time Complexity: O(2^N)
// Space Complexity: O(N) (Recursion Stack)
int knapsackRecursive(int W, vector<int>& wt, vector<int>& val, int n) {
    // Base Case
    if (n == 0 || W == 0) return 0;

    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if (wt[n - 1] > W)
        return knapsackRecursive(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1] + knapsackRecursive(W - wt[n - 1], wt, val, n - 1),
            knapsackRecursive(W, wt, val, n - 1)
        );
}

// 2. Top-Down DP (Memoization)
// Time Complexity: O(N * W)
// Space Complexity: O(N * W) + O(N) (Table + Stack)
int memo[102][1002]; // Assuming N <= 100, W <= 1000
int knapsackMemo(int W, vector<int>& wt, vector<int>& val, int n) {
    if (n == 0 || W == 0) return 0;
    // W: current capacity, n: current number of items considered
    // Check if the result for the state (n, W) is already calculated
    if (memo[n][W] != -1) return memo[n][W];

    if (wt[n - 1] > W)
        return memo[n][W] = knapsackMemo(W, wt, val, n - 1);
    else
        return memo[n][W] = max(
            val[n - 1] + knapsackMemo(W - wt[n - 1], wt, val, n - 1),
            knapsackMemo(W, wt, val, n - 1)
        );
}

// 3. Bottom-Up DP (Tabulation)
// Time Complexity: O(N * W)
// Space Complexity: O(N * W)
int knapsackTabulation(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();

    cout << "Max Value (Recursive): " << knapsackRecursive(W, wt, val, n) << endl;

    // Initialize memo table
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=W; ++j)
            memo[i][j] = -1;
            
    cout << "Max Value (Top-Down): " << knapsackMemo(W, wt, val, n) << endl;

    cout << "Max Value (Bottom-Up): " << knapsackTabulation(W, wt, val, n) << endl;

    return 0;
}

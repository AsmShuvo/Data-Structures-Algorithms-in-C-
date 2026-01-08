#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ==========================================
// Topic: Coin Change (Minimum Coins)
// ==========================================

// 1. Recursive Solution
// Time Complexity: Exponential
// Space Complexity: O(Amount) (Recursion Stack)
int minCoins(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;

    int res = INT_MAX;

    for (int coin : coins)
    {
        if (coin <= amount)
        {
            int sub_res = minCoins(coins, amount - coin);

            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return res;
}

// 2. Top-Down DP (Memoization)
// Time Complexity: O(Amount * N)
// Space Complexity: O(Amount)
int memo[10001]; // Adjust based on max amount
int coinChnageMemo(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    if (memo[amount]!=-1)
        return memo[amount];

    int res = INT_MAX;

    for (int coin : coins)
    {
        if (coin <= amount)
        {
            int sub_res = coinChnageMemo(coins, amount - coin);

            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return memo[amount] = res;
}


// 3. Bottom-Up DP (Tabulation)
// Time Complexity: O(Amount * N)
// Space Complexity: O(Amount)
int coinChangeTabulation(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 13;

    cout << "Min Coins (Recursive): " << minCoins(coins, amount) << endl;

    // Initialize memo table
    for (int i = 0; i <= amount; ++i)
        memo[i] = -1;
    int res = coinChangeMemo(coins, amount);
    cout << "Min Coins (Top-Down): " << (res == INT_MAX ? -1 : res) << endl;

    cout << "Min Coins (Bottom-Up): " << coinChangeTabulation(coins, amount) << endl;

    return 0;
}

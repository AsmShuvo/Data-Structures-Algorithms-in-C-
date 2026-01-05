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
int coinChangeRecursive(const vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;

    int minCoins = INT_MAX;
    for (int coin : coins) {
        int res = coinChangeRecursive(coins, amount - coin);
        if (res != INT_MAX) {
            minCoins = min(minCoins, res + 1);
        }
    }
    return minCoins;
}

// 2. Top-Down DP (Memoization)
// Time Complexity: O(Amount * N)
// Space Complexity: O(Amount)
int memo[10001]; // Adjust based on max amount
int coinChangeMemo(const vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;
    
    if (memo[amount] != -1) return memo[amount];

    int minCoins = INT_MAX;
    for (int coin : coins) {
        int res = coinChangeMemo(coins, amount - coin);
        if (res != INT_MAX) {
            minCoins = min(minCoins, res + 1);
        }
    }
    return memo[amount] = minCoins;
}

// 3. Bottom-Up DP (Tabulation)
// Time Complexity: O(Amount * N)
// Space Complexity: O(Amount)
int coinChangeTabulation(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Min Coins (Recursive): " << coinChangeRecursive(coins, amount) << endl;

    // Initialize memo table
    for(int i=0; i<=amount; ++i) memo[i] = -1;
    int res = coinChangeMemo(coins, amount);
    cout << "Min Coins (Top-Down): " << (res == INT_MAX ? -1 : res) << endl;

    cout << "Min Coins (Bottom-Up): " << coinChangeTabulation(coins, amount) << endl;

    return 0;
}

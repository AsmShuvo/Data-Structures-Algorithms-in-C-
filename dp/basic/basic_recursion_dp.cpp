#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// Topic: Basic Recursion and Dynamic Programming
// Example: Fibonacci Sequence
// ==========================================

// 1. Recursive Solution (Exponential Time)
// Time Complexity: O(2^N)
// Space Complexity: O(N) (Recursion Stack)
int fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// 2. Top-Down DP (Memoization)
// Time Complexity: O(N)
// Space Complexity: O(N) + O(N) (Recursion Stack + Memo Table)
int memo[1000]; // Adjust size as needed
int fibMemo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

// 3. Bottom-Up DP (Tabulation)
// Time Complexity: O(N)
// Space Complexity: O(N)
int fibTabulation(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 4. Space Optimized Bottom-Up
// Time Complexity: O(N)
// Space Complexity: O(1)
int fibSpaceOptimized(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n = 10;
    cout << "Fibonacci of " << n << " (Recursive): " << fibRecursive(n) << endl;

    // Initialize memo table with -1
    for(int i=0; i<1000; ++i) memo[i] = -1;
    cout << "Fibonacci of " << n << " (Top-Down): " << fibMemo(n) << endl;

    cout << "Fibonacci of " << n << " (Bottom-Up): " << fibTabulation(n) << endl;
    cout << "Fibonacci of " << n << " (Space Optimized): " << fibSpaceOptimized(n) << endl;

    return 0;
}

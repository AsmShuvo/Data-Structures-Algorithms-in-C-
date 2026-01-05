#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// Topic: Longest Common Subsequence (LCS)
// ==========================================

// 1. Recursive Solution
// Time Complexity: O(2^N)
// Space Complexity: O(N)
int lcsRecursive(const string& s1, const string& s2, int i, int j) {
    if (i == s1.length() || j == s2.length()) return 0;

    if (s1[i] == s2[j])
        return 1 + lcsRecursive(s1, s2, i + 1, j + 1);
    else
        return max(lcsRecursive(s1, s2, i + 1, j), lcsRecursive(s1, s2, i, j + 1));
}

// 2. Top-Down DP (Memoization)
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
int memo[1001][1001];
int lcsMemo(const string& s1, const string& s2, int i, int j) {
    if (i == s1.length() || j == s2.length()) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i] == s2[j])
        return memo[i][j] = 1 + lcsMemo(s1, s2, i + 1, j + 1);
    else
        return memo[i][j] = max(lcsMemo(s1, s2, i + 1, j), lcsMemo(s1, s2, i, j + 1));
}

// 3. Bottom-Up DP (Tabulation)
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
int lcsTabulation(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    string s1 = "abcde";
    string s2 = "ace"; 

    cout << "LCS Length (Recursive): " << lcsRecursive(s1, s2, 0, 0) << endl;

    // Initialize memo table
    for(int i=0; i<=s1.length(); ++i)
        for(int j=0; j<=s2.length(); ++j)
            memo[i][j] = -1;

    cout << "LCS Length (Top-Down): " << lcsMemo(s1, s2, 0, 0) << endl;

    cout << "LCS Length (Bottom-Up): " << lcsTabulation(s1, s2) << endl;

    return 0;
}

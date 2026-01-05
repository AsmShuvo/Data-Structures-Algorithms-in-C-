#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// Topic: Longest Increasing Subsequence (LIS)
// ==========================================

// 1. Recursive Solution
// Time Complexity: O(2^N)
// Space Complexity: O(N)
int lisRecursive(const vector<int>& nums, int prev_idx, int curr_idx) {
    if (curr_idx == nums.size()) return 0;

    // Option 1: Exclude current element
    int len = lisRecursive(nums, prev_idx, curr_idx + 1);

    // Option 2: Include current element (if valid)
    if (prev_idx == -1 || nums[curr_idx] > nums[prev_idx]) {
        len = max(len, 1 + lisRecursive(nums, curr_idx, curr_idx + 1));
    }

    return len;
}

// 2. Top-Down DP (Memoization)
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
int memo[2501][2501]; // N <= 2500
int lisMemo(const vector<int>& nums, int prev_idx, int curr_idx) {
    if (curr_idx == nums.size()) return 0;
    
    // prev_idx + 1 because prev_idx can be -1
    if (memo[prev_idx + 1][curr_idx] != -1) return memo[prev_idx + 1][curr_idx];

    int len = lisMemo(nums, prev_idx, curr_idx + 1);

    if (prev_idx == -1 || nums[curr_idx] > nums[prev_idx]) {
        len = max(len, 1 + lisMemo(nums, curr_idx, curr_idx + 1));
    }

    return memo[prev_idx + 1][curr_idx] = len;
}

// 3. Bottom-Up DP (Tabulation)
// Time Complexity: O(N^2)
// Space Complexity: O(N)
int lisTabulation(const vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "LIS Length (Recursive): " << lisRecursive(nums, -1, 0) << endl;

    // Initialize memo table
    int n = nums.size();
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=n; ++j)
            memo[i][j] = -1;
            
    cout << "LIS Length (Top-Down): " << lisMemo(nums, -1, 0) << endl;

    cout << "LIS Length (Bottom-Up): " << lisTabulation(nums) << endl;

    return 0;
}

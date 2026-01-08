# Dynamic Programming Resources

This folder contains beginner-friendly explanations and C++ implementations for fundamental Dynamic Programming (DP) concepts.

## 1. Basic Recursion and Dynamic Programming

**Explanation:**

- **Recursion:** A function calling itself to solve smaller instances of the same problem. It has a base case to stop.
- **Dynamic Programming (DP):** An optimization over plain recursion. It stores the results of subproblems so that we don't re-calculate them. This is useful when the problem has _overlapping subproblems_ and _optimal substructure_.

**Approaches:**

1.  **Top-Down (Memoization):**
    - Start from the main problem and break it down.
    - Store the result of each subproblem in a table (array/map) when you compute it.
    - Before computing, check if the result is already in the table.
    - _Why:_ Natural to write if you already have the recursive solution.
2.  **Bottom-Up (Tabulation):**
    - Start from the smallest subproblems (base cases) and build up to the main problem.
    - Fill a table iteratively.
    - _Why:_ Usually saves stack space (no recursion overhead) and can sometimes be optimized further (space optimization).

**Complexity:**

- **Time:** Depends on the number of unique states. Usually O(N) or O(N\*M).
- **Space:** O(N) or O(N\*M) for the table.

**Popular Problems:**

1.  [Climbing Stairs (LeetCode)](https://leetcode.com/problems/climbing-stairs/)
2.  [Fibonacci Number (LeetCode)](https://leetcode.com/problems/fibonacci-number/)
3.  [House Robber (LeetCode)](https://leetcode.com/problems/house-robber/)

---

## 2. 0-1 Knapsack Problem

**Explanation:**
You have a bag with capacity `W` and `N` items, each with a weight and a value. You want to maximize the total value in the bag. For each item, you can either **take it (1)** or **leave it (0)**. You cannot break items.

**Approaches:**

- **Top-Down:** `dp(index, remaining_weight)` returns max value.
- **Bottom-Up:** `dp[i][w]` = max value using first `i` items with capacity `w`.

**Complexity:**

- **Time:** O(N \* W) where N is items, W is capacity.
- **Space:** O(N \* W) (can be optimized to O(W) in Bottom-Up).

**Popular Problems:**

1.  [Partition Equal Subset Sum (LeetCode)](https://leetcode.com/problems/partition-equal-subset-sum/)
2.  [Target Sum (LeetCode)](https://leetcode.com/problems/target-sum/)
3.  [Knapsack Problem (Spoj)](https://www.spoj.com/problems/KNAPSACK/)

---

## 3. Coin Change

**Explanation:**
Given coins of different denominations and a total amount, find the **minimum number of coins** needed to make up that amount. (Another variation is finding the number of ways to make the amount).

**Approaches:**

- **Top-Down:** `dp(amount)` = 1 + min(dp(amount - coin)) for all coins.
- **Bottom-Up:** `dp[i]` = min coins for amount `i`.

**Complexity:**

- **Time:** O(Amount \* Number_of_Coins).
- **Space:** O(Amount).

**Popular Problems:**

1.  [Coin Change (LeetCode)](https://leetcode.com/problems/coin-change/)
2.  [Coin Change II (Number of ways) (LeetCode)](https://leetcode.com/problems/coin-change-ii/)
3.  [Minimizing Coins (CSES)](https://cses.fi/problemset/task/1634)

### Note: you should take `unsigned long long int` for coin change problem for safety

---

## 4. Longest Increasing Subsequence (LIS)

**Explanation:**
Find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. A subsequence doesn't need to be contiguous.

**Approaches:**

- **Top-Down:** `dp(index, prev_index)`
- **Bottom-Up:** `dp[i]` = length of LIS ending at index `i`. Check all `j < i` where `arr[j] < arr[i]`.

**Complexity:**

- **Time:** O(N^2) for standard DP. (There is an O(N log N) solution using Binary Search, but standard DP is O(N^2)).
- **Space:** O(N).

### Note: There is also another method of finding the LIS with binary search.

- Time Complexity: O(N log N)
- Space complexity: O(N)

**Popular Problems:**

1.  [Longest Increasing Subsequence (LeetCode)](https://leetcode.com/problems/longest-increasing-subsequence/)
2.  [Russian Doll Envelopes (LeetCode)](https://leetcode.com/problems/russian-doll-envelopes/)
3.  [Maximum Length of Pair Chain (LeetCode)](https://leetcode.com/problems/maximum-length-of-pair-chain/)

---

## 5. Longest Common Subsequence (LCS)

**Explanation:**
Given two strings, find the length of the longest subsequence present in both of them.

**Approaches:**

- **Top-Down:** `dp(i, j)` for strings A and B. If `A[i] == B[j]`, then `1 + dp(i+1, j+1)`. Else `max(dp(i+1, j), dp(i, j+1))`.
- **Bottom-Up:** `dp[i][j]` stores LCS of `A[0...i]` and `B[0...j]`.

**Complexity:**

- **Time:** O(N \* M) where N and M are lengths of strings.
- **Space:** O(N \* M).

**Popular Problems:**

1.  [Longest Common Subsequence (LeetCode)](https://leetcode.com/problems/longest-common-subsequence/)
2.  [Edit Distance (LeetCode)](https://leetcode.com/problems/edit-distance/)
3.  [Distinct Subsequences (LeetCode)](https://leetcode.com/problems/distinct-subsequences/)

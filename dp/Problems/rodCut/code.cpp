#include <bits/stdc++.h>
using namespace std;

/*****************************
 * Time Complexity: O(n×m)
 * (Auxiliary Space) (excluding input data) Space Complexity: O(n)
 ***************************/

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cost(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> cost[i];
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int len = 1; len <= n; len++)
    {
        int profit = 0;
        for (int j = 1; j <= len && j <= m; j++)
        {
            profit = max(profit, dp[len - j] + cost[j]);
        }
        dp[len] = profit;
    }
    cout << dp[n] << endl;
}

/*
    2^n approach (naive)
    #include <bits/stdc++.h>
using namespace std;

// Function to compute the maximum profit using the 2^n approach
int rodCutting(int n, vector<int>& cost) {
    // Base case: If the length of the rod is 0, return 0 profit
    if (n == 0) return 0;

    int maxProfit = 0;

    // Try cutting the rod at all lengths from 1 to n
    for (int i = 1; i <= n; i++) {
        // Profit for current cut: cost[i] + profit of the remaining rod length
        int profit = cost[i] + rodCutting(n - i, cost);
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cost(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> cost[i];
    }

    // Get the maximum profit using the brute force recursive approach
    int maxProfit = rodCutting(n, cost);

    cout << maxProfit << endl;

    return 0;
}

*/

/*
 confusion: j < len wont work because when j == len, we can take the
 whole rod of length 'len' and get its cost. If we use j < len,
 we would miss this case and potentially get a lower profit.
 Hence, the correct condition is j <= len.
*/
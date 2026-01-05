#include <bits/stdc++.h>
using namespace std;

/****************************
 * Time Complexity: O(n×t)  *
 * Space Complexity: O(n×t) *
 ***************************/
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // Initialize dp table with false
    vector<vector<bool>> dp(n + 1, vector<bool>(t + 1, false));

    // Base case: sum of 0 is always possible with no items
    dp[0][0] = true;

    // Fill the dp table
    for (int i = 1; i <= n; i++)
    {
        for (int sum = 0; sum <= t; sum++)
        {
            // If we don't take the i-th item (v[i-1])
            dp[i][sum] = dp[i - 1][sum];

            // If sum >= v[i-1], check if it's possible to form sum by including v[i-1]
            if (sum >= v[i - 1])
            {
                dp[i][sum] = dp[i][sum] || dp[i - 1][sum - v[i - 1]];
            }
        }
    }

    // Output the result for dp[n][t], which tells us if it's possible to form sum t
    cout << (dp[n][t] ? "YES" : "NO") << endl;

    return 0;
}

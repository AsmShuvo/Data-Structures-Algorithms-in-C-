#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++)
        dp[n][i] = 1;
    for (int i = 1; i <= n; i++)
        dp[i][m] = 1;

    for (int i = n-1; i >= 1; i--)
    {
        for (int j = m-1; j >= 1; j--)
        {
            if (!dp[i][j])
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
    }
    cout << dp[1][1] << endl;
}
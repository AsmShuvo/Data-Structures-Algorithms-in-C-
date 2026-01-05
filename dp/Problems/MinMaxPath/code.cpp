#include <bits/stdc++.h>
using namespace std;
const int inf = 1e12;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1, inf));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }
    dp[n][m] = v[n][m];

    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            if (i == n && j == m)
                continue;
            if (i == n)
                dp[i][j] = v[i][j] + dp[i][j + 1];
            else if (j == m)
                dp[i][j] = v[i][j] + dp[i + 1][j];
            else
                dp[i][j] = v[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    
    cout <<"(1,1)--> (n,m): "<< dp[1][1] << endl;
    // return 0;

    // from top row to bottom row
    const int INF = 1e12;
    vector<vector<long long>> dp2(n + 2, vector<long long>(m + 2, INF));
    dp2[n][m] = v[n][m];

    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            if (i == n && j == m)
                continue;
            if (i == n)
                dp2[i][j] = v[i][j] + dp2[i][j + 1];
            else if (j == m)
                dp2[i][j] = v[i][j] + dp2[i + 1][j];
            else
                dp2[i][j] = v[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
        }
    }

    cout <<"(row 1)--> (row n): "<<  dp2[1][1] << "\n";
}
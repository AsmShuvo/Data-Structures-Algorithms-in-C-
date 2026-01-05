#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    // oth and 1st row
    for (int i = 0; i <= n; i++)
        dp[0][i] = dp[1][i] = 1;

    for (int len = 2; len <= n; len++)
    {
        for (int end = len; end <= n; end++)
        {
            int start = end - len + 1;
            if (s[end - 1] == s[start - 1] && dp[len - 2][end - 1])
            {
                dp[len][end] = 1;
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j])
                ans = max(ans, i);
        }
    }
    cout << ans << endl;
    return 0;
}
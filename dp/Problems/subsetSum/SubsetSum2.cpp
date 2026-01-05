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

    vector<int> dp(t + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int cur = v[i];
        for (int j = t; j >= cur; j--)
        {
            if (dp[j] || (dp[j - cur] == 0))
                continue;
            else
                dp[j] = 1;
        }
    }
    // for (int i = 0; i <= t; i++)
    //     cout << dp[i] << " ";
    // cout << endl;
    cout << (dp[t] ? "YES" : "NO") << " ";
}

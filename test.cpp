#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> v(n + 2, 0);
        int c0 = 0;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if (x <= n + 1)
                v[x]++;
            if (x == 0)
                c0++;
        }

        int mex = 0;
        while (v[mex] > 0)
        {
            mex++;
        }

        string ans = "NO";
        if (c0 == 1)
        {
            ans = "YES";
        }
        else if (c0 >= 2 && mex >= 2)
        {
            ans = "YES";
        }

        cout << ans << '\n';
    }

    return 0;
}
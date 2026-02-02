#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n, int k)
{
    sort(v.begin(), v.end());
    int s = 0;
    for (int i = 0; i < k; i++)
        s += v[i];
    int baki = n - k;
    s += (baki * v[k - 1]);
    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        if (k == 0)
        {
            cout << 0 << endl;
        }
        else
            cout << solve(a, n, k) << endl;
    }
}
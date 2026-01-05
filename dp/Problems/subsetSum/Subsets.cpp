#include <bits/stdc++.h>
using namespace std;
/*****************************
 * Time Complexity: O(n×sum) *
 * Space Complexity: O(sum)  *
 ***************************/
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> pre(sum + 1);
    pre[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int cur = arr[i];
        for (int j = sum; j >= cur; j--)
        {
            if (pre[j] || pre[j - cur] == 0)
                continue;
            else
                pre[j] = cur;
        }
    }
    // for (int i = 0; i <= sum; i++)
    //     cout << pre[i] << " ";
    if (!pre[sum])
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    while (sum)
    {
        cout << pre[sum] << " ";
        sum -= pre[sum];
    }
}
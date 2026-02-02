#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        int dp[2][2], ndp[2][2];
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++)
                dp[a][b] = INF;

        for (int x = 0; x <= 1; x++) {
            if (s[0] == '1' && x == 0) continue;
            for (int y = 0; y <= 1; y++) {
                if (s[1] == '1' && y == 0) continue;

                if (x == 1 && y == 1) continue;

                if (x == 0 && y == 0) continue;

                dp[x][y] = min(dp[x][y], x + y);
            }
        }

        if (n == 2) {
            int ans = INF;
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    ans = min(ans, dp[a][b]);
            cout << ans << "\n";
            continue;
        }

        for (int i = 2; i < n; i++) {
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    ndp[a][b] = INF;

            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    if (dp[a][b] >= INF) continue;

                    for (int c = 0; c <= 1; c++) {
                        if (s[i] == '1' && c == 0) continue;

                        if (b == 1 && c == 1) continue;

                        if (a == 0 && b == 0 && c == 0) continue;

                        ndp[b][c] = min(ndp[b][c], dp[a][b] + c);
                    }
                }
            }
            memcpy(dp, ndp, sizeof(dp));
        }

        int ans = INF;
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                if (a == 0 && b == 0) continue;
                ans = min(ans, dp[a][b]);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

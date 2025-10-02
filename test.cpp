#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    sort(a.begin(), a.end());
    
    ll ans = LLONG_MAX;
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i-1]) continue;
        int k = (m - a[i]) % m;
        auto it = lower_bound(a.begin(), a.end(), m - k);
        ll wc = a.end() - it;
        ll cs = tot + (ll)n * k - (ll)m * wc;
        ans = min(ans, cs);
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
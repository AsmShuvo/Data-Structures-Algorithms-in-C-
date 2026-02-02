#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool f(vector<ll>& a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b;
        ll mn = 4e18, mx = -4e18;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }

        if (f(a)) {
            cout << -1 << "\n";
            continue;
        }

        b = a;
        sort(b.begin(), b.end());

        vector<ll> v1 = a;
        sort(v1.begin(), v1.end());
        v1.erase(unique(v1.begin(), v1.end()), v1.end());
        int m = v1.size();

        unordered_map<ll, int> id;
        id.reserve(m * 2);
        id.max_load_factor(0.7f);
        for (int i = 0; i < m; i++) id[v1[i]] = i;

        vector<int> ida(n), idb(n);
        for (int i = 0; i < n; i++) {
            ida[i] = id[a[i]];
            idb[i] = id[b[i]];
        }

        auto can = [&](ll k) -> bool {
            vector<int> comp(m, -1);
            set<int> us;
            for (int i = 0; i < m; i++) us.insert(i);

            int cid = 0;
            queue<int> q;

            while (!us.empty()) {
                int start = *us.begin();
                us.erase(us.begin());
                comp[start] = cid;
                q.push(start);

                while (!q.empty()) {
                    int idx = q.front();
                    q.pop();
                    ll x = v1[idx];

                    ll leftLimit = x - k;
                    int L = upper_bound(v1.begin(), v1.end(), leftLimit) - v1.begin();

                    ll rightLimit = x + k;
                    int R = lower_bound(v1.begin(), v1.end(), rightLimit) - v1.begin();

                    auto it = us.begin();
                    while (it != us.end() && *it < L) {
                        int j = *it;
                        it = us.erase(it);
                        comp[j] = cid;
                        q.push(j);
                    }

                    it = us.lower_bound(R);
                    while (it != us.end()) {
                        int j = *it;
                        it = us.erase(it);
                        comp[j] = cid;
                        q.push(j);
                    }
                }

                cid++;
            }

            for (int i = 0; i < n; i++) {
                if (comp[ida[i]] != comp[idb[i]]) return false;
            }
            return true;
        };

        ll range = mx - mn;
        ll lo = 0, hi = range + 1; 
        while (lo + 1 < hi) {
            ll mid = (lo + hi) / 2;
            if (can(mid)) lo = mid;
            else hi = mid;
        }

        cout << lo << "\n";
    }

    return 0;
}

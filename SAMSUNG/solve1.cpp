#include <bits/stdc++.h>
using namespace std;

bool ok = true;

// Time: O(v+e) Space: O(v+e)
void dfs(vector<vector<int>> &g, vector<bool> &vis, vector<int> &color, int v, int p)
{
    if (!ok)
        return;
    vis[v] = true;
    if (p >= 0)
        color[v] = !color[p];
    for (auto u : g[v])
    {
        if (vis[u] && u != p && color[u] == color[v])
        {
            ok = false;
            return;
        }
        if (!vis[u])
        {
            dfs(g, vis, color, u, v);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ok = true;
        int v, e;
        cin >> v >> e;
        vector<vector<int>> g(v + 1);
        vector<bool> vis(v + 1, false);
        vector<int> color(v + 1);
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
                dfs(g, vis, color, i, -1);
        }
        if (!ok)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 1; i <= v; i++)
            {
                if (color[i])
                    cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

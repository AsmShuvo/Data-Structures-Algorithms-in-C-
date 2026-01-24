#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int> path, par;

void dfs(int v, int p)
{
    vis[v] = 1;
    for (auto u : g[v])
    {
        if (vis[u] == 1)
        {
            // cycle found
            int cur = v;
            path.push_back(u);
            while (cur != u)
            {
                path.push_back(cur);
                cur = par[cur];
            }
            path.push_back(u);
            reverse(path.begin(), path.end());
            return;
        }
        if (!vis[u])
        {
            par[u] = v;
            dfs(u, v);
            if (path.size())
                return;
        }
    }
    vis[v] = 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    par.resize(n + 1, -1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && path.size() == 0)
            dfs(i, -1);
    }
    if (path.size())
    {
        cout << path.size() << endl;
        for (auto it : path)
            cout << it << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
}
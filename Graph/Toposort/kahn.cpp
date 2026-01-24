#include <bits/stdc++.h>
using namespace std;

vector<int> List;
bool kahnToposort(int n, vector<vector<int>> &g)
{
    vector<int> ind(n, 0);
    queue<int> q;
    // Note: O(n+e) not O(n*e)
    for (int i = 0; i < n; i++)
    {
        for (auto v : g[i])
        {
            ind[v]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    // we are pushing n nodes and checking all edges for each node only once 
    // so O(n+e)
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        List.push_back(u);
        for (auto v : g[u])
        {
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
            }
        }
    }
    if (List.size() == n)
        return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        g[v].push_back(u);
    }
    if (kahnToposort(n, edges))
    {
        cout << "POSSIBLE" << endl;
        for (auto it : List)
            cout << it << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE, Cycle Detected" << endl;
    return 0;
}
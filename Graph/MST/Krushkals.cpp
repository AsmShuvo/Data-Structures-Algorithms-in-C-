#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> par, sz;

    DSU(int n)
    {
        par.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }

    int find(int v)
    {
        if (par[v] == v)
        {
            return v;
        }
        return par[v] = find(par[v]);
    }

    void unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (sz[u] < sz[v])
                swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b)
{
    return (a[2] < b[2]);
}

void kruskalsMST(int n, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dsu.find(u) != dsu.find(v))
        {
            dsu.unite(u, v);
            cout << u << "-" << v << ":" << wt << endl;
        }
    }
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}};

    kruskalsMST(4, edges);
}

/*
    Sorting all edges: O(E log E)
    DSU initialization: O(V)
    DSU unite and find: O(α(n))
    so, Time=O(ElogE+V+E⋅α(V))
    Space: O(v+e) v=for par and sz array e= for the edge vector
*/
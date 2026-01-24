#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dijkstra(vector<vector<pair<int, int>>> &g, int n, int src)
    {
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int u = it.second, d = it.first;
            if (dist[u] < d)
                continue;
            for (auto node : g[u])
            {
                int v = node.first;
                int wt = node.second;
                if (dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>> &edges, int n, int k)
    {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
        }
        return dijkstra(g, n, k);
    }
};

// time complexity: O((V + E) log V)
// space complexity: O(V + E)

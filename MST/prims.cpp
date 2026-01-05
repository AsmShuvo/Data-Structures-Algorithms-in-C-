#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int prims(int start_node, int V, vector<vector<pii>> &adj)
{
    // Min-heap: priority_queue<Type, Container, Comparator>
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<bool> visited(V, false);
    int mst_weight = 0;

    // Start with the first node: (weight 0, node)
    pq.push({0, start_node});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the node is already in the MST, skip it
        if (visited[u])
            continue;

        // Include node in MST
        visited[u] = true;
        mst_weight += weight;

        // Check all neighbors
        for (auto &edge : adj[u])
        {
            int v = edge.second;
            int w = edge.first;
            if (!visited[v])
            {
                pq.push({w, v});
            }
        }
    }
    return mst_weight;
}

int main()
{
    int V = 4;
    vector<vector<pii>> adj(V);

    // Adding edges: adj[u].push_back({weight, v})
    adj[0].push_back({2, 1});
    adj[1].push_back({2, 0});
    adj[0].push_back({6, 2});
    adj[2].push_back({6, 0});
    adj[1].push_back({3, 3});
    adj[3].push_back({3, 1});
    adj[2].push_back({1, 3});
    adj[3].push_back({1, 2});

    cout << "Total MST Weight: " << prims(0, V, adj) << endl;

    return 0;
}
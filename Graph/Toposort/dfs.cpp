#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> List; // To store the topological order
    vector<bool> visited; // To track visited nodes
    vector<bool> inStack; // To detect cycles (for cycle detection)
    
    bool dfs(int node, vector<vector<int>>& g) {
        // If the node is in the recursion stack, a cycle is detected
        if (inStack[node]) 
            return false; // There's a cycle, so topological sort is not possible
        
        // If the node has been visited already, no need to explore it again
        if (visited[node])
            return true;
        
        // Mark the node as visited and add it to the recursion stack
        visited[node] = true;
        inStack[node] = true;
        
        // Visit all the adjacent nodes
        for (auto v : g[node]) {
            if (!dfs(v, g)) // If any neighbor causes a cycle, return false
                return false;
        }
        
        // Once all the neighbors of the current node are processed, add to the topological order
        inStack[node] = false; // Remove from recursion stack
        List.push_back(node); // Add the node to the topological sort list
        
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n); // Graph represented as an adjacency list
        
        // Build the graph
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
        }
        
        visited.resize(n, false); // To track visited nodes
        inStack.resize(n, false); // To track nodes in the recursion stack
        
        // Perform DFS on all nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!dfs(i, g)) {
                    return false; // If a cycle is detected, return false
                }
            }
        }
        
        // If no cycle is found, return true and List contains the topological order
        reverse(List.begin(), List.end()); // Reverse the list to get the correct order
        return true;
    }
};

// time complexity: O(n + e) 
// space complecity: O(n + e) 
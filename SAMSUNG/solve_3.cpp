#include <bits/stdc++.h>
using namespace std;

int n, m;
int sr, sc, dr, dc;
vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {-1, 1, -1, 1, -2, -2, 2, 2};

int bfs()
{
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    vis[sr][sc] = 1;
    queue<vector<int>> q;
    // r c step
    q.push({sr, sc, 0});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur[0], y = cur[1], step = cur[2];
        if (x == dr && y == dc)
            return step; // found
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            q.push({nx, ny, step + 1});
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin >> sr >> sc >> dr >> dc;
        cout << bfs() << endl;
    }
}

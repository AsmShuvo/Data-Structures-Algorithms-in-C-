#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tl;
    if (!(cin >> tl)) return 0;
    while (tl--)
    {
        int n, m, total_time;
        cin >> n >> m >> total_time;
        int steps = total_time / 10;
        
        vector<vector<pair<int, double>>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            double p;
            cin >> u >> v >> p;
            g[u].push_back({v, p});
        }
        
        vector<double> prob(n + 1, 0.0);
        prob[1] = 1.0;

        for (int s = 0; s < steps; s++)
        {
            vector<double> nextProb(n + 1, 0.0);
            for (int u = 1; u <= n; u++)
            {
                if (prob[u] > 0)
                {
                    for (auto &e : g[u])
                    {
                        int v = e.first;
                        double pb = e.second; 
                        nextProb[v] += prob[u] * pb;
                    }
                }
            }
            prob = nextProb;
        }

        int lastNode = -1;
        double mxProb = -1.0; 

        for (int i = 1; i <= n; i++)
        {
            if (prob[i] > mxProb)
            {
                mxProb = prob[i];
                lastNode = i;
            }
        }

        if (lastNode == -1 || mxProb <= 0.0)
            cout << "impossible" << endl;
        else
            cout << lastNode << " " << fixed << setprecision(6) << mxProb << endl;
    }
    return 0;
}
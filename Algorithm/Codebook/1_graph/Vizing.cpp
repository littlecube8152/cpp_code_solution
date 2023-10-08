#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

#define mxN 105

// returns edge coloring in adjacent matrix G (1-based)
namespace Vizing
{
    int C[mxN][mxN], G[mxN][mxN], f[mxN], vis[mxN];
    void solve(vector<pii> E, int N)
    {
        for (int i = 1; i <= N; i++)
        {
            fill(C[i], C[i] + 1 + N, 0);
            fill(G[i], G[i] + 1 + N, 0);
            f[i] = 1;
        }
        auto findfree = [&](int u)
        { f[u] = (int)(min_element(C[u] + 1, C[u] + 1 + N) - C[u]); };
        auto flip = [&](int u, int c, int d, auto flip) -> void
        {
            if (C[u][c])
            {
                int v = C[u][c];
                flip(v, d, c, flip);
                G[u][v] = G[v][u] = d;
            }
            else
                f[u] = d;
            swap(C[u][c], C[u][d]);
        };
        for (auto [a, b] : E)
        {
            vector<pii> ch;
            auto recolor = [&](int u, int v)
            {
                ch.clear();
                fill(vis + 1, vis + 1 + N, 0);
                vis[v] = 1;
                ch.emplace_back(v, f[v]);
                while (C[u][f[v]])
                {
                    v = C[u][f[v]];
                    if (vis[v])
                    {
                        int c = G[u][v], d = f[u];
                        flip(u, c, d, flip);
                        f[u] = c;
                        return false;
                    }
                    vis[v] = 1;
                    ch.emplace_back(v, f[v]);
                }
                return true;
            };

            if(!recolor(a, b))
                recolor(a, b);

            reverse(ch.begin(), ch.end());
            for (auto [v, c] : ch)
            {
                int d = G[a][v];
                G[a][v] = G[v][a] = c;
                swap(C[a][c], C[a][d]);
                swap(C[v][c], C[v][d]);
                f[v] = d;
            }
            int c = G[a][b];
            C[a][0] = 0, C[b][0] = 0;
            C[a][c] = b, C[b][c] = a;
            findfree(a);
            findfree(b);
        }
    }
}
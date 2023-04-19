#include "split.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;
 
int N, M, pre[100000], vis[100000], s[100000], d[100000], use[200000], color[3] = {1, 2, 3};
pii jump[100000];
vector<int> sol, F[100000];
vector<pii> E[100000];
 
void dfs(int u)
{
    s[u] = vis[u] = 1;
    jump[u] = pii(N, -1);
    for (auto [v, i] : E[u])
        if (!vis[v])
        {
            use[i] = 1;
            d[v] = d[u] + 1;
            pre[v] = u;
            dfs(v);
            s[u] += s[v];
            jump[u] = min(jump[u], jump[v]);
        }
        else if (v != pre[u] && d[v] < d[u])
            jump[u] = min(jump[u], pii(d[v], i));
}
 
void construct(int u, int &cnt, int color)
{
    if (cnt > 0)
        cnt--, sol[u] = color;
    for (auto v : F[u])
        if (!vis[v])
        {
            vis[v] = 1;
            construct(v, cnt, color);
        }
}
 
vector<int> find_split(int n, int a, int b, int c, vector<int> p, vector<int> q)
{
    N = n, M = p.size();
    if (a > c)
        swap(a, c), swap(color[0], color[2]);
    if (b > c)
        swap(b, c), swap(color[1], color[2]);
 
    for (int i = 0; i < M; i++)
        E[p[i]].emplace_back(pii(q[i], i)), E[q[i]].emplace_back(pii(p[i], i));
 
    sol = vector<int>(N, color[2]);
    dfs(0);
 
    for (int _ = 0; _ <= 1; _++)
    {
        for (int u = 1; u < N; u++)
        {
            if (s[u] >= a)
            {
                vector<int> add, del;
                int k = n - s[u];
                for (auto [v, i] : E[u])
                    if (pre[v] == u && k < b && s[v] < a)
                        if (jump[v].F < d[u])
                        {
                            add.emplace_back(jump[v].S);
                            del.emplace_back(i);
                            k += s[v];
                        }
                if (k >= b)
                {
                    for (int i : add)
                        use[i] = 1;
                    for (int i : del)
                        use[i] = 0;
                    for (int i = 0; i < M; i++)
                        if(use[i])
                            F[p[i]].emplace_back(q[i]), F[q[i]].emplace_back(p[i]);
                    for (int i = 0; i < N; i++)
                        vis[i] = 0;
                    vis[u] = vis[pre[u]] = 1;
                    construct(u, a, color[0]);
                    construct(pre[u], b, color[1]);
                    return sol;
                }
            }
        }
        swap(a, b);
        swap(color[0], color[1]);
    }
 
    return vector<int>(N, 0);
}
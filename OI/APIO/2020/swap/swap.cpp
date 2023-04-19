#include "swap.h"
#ifndef EVAL
#include "grader.cpp"
#endif
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

namespace
{
    int N, M, K, t, dp[300000], dsu[100000], rk[100000], node[100000], pre[300000][20];
    int chain[100000][2];
    pii io[300000];
    vector<pair<int, pii>> edge;
    vector<int> E[300000];

    int find(int k)
    {
        return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
    }

    void merge(int x, int y, int u, int v, int w)
    {
        x = find(x), y = find(y);
        if (x == y)
        {
            chain[x][0] = chain[x][1] = -1;
            dp[++K] = w;
            E[K].emplace_back(node[x]);
            node[x] = K;
            return;
        }
        if (rk[x] < rk[y])
        {
            merge(y, x, u, v, w);
            return;
        }
        dsu[y] = x;
        rk[x] += rk[y];
        bool flag = 0;
        //fprintf(stderr, "(%d, %d) (%d, %d) (%d, %d) -> ", chain[x][0], chain[x][1], u, v, chain[y][0], chain[y][1]);
        for (int i = 0; (!flag) && i < 2; i++)
            for (int j = 0; (!flag) && j < 2; j++)
                if ((chain[x][i] == u && chain[y][j] == v) || (chain[x][i] == v && chain[y][j] == u))
                {
                    flag = 1;
                    chain[x][i] = chain[y][j ^ 1];
                }
        if (!flag)
            chain[x][0] = chain[x][1] = -1;
        if (chain[x][0] != -1)
            w = 2e9;
        //fprintf(stderr, "(%d, %d)\n", chain[x][0], chain[x][1]);
        dp[++K] = w;
        E[K].emplace_back(node[x]);
        E[K].emplace_back(node[y]);
        node[x] = K;
    }

    void dfs(int u)
    {
        io[u].F = ++t;
        for (auto v : E[u])
        {
            pre[v][0] = u;
            dp[v] = min(dp[v], dp[u]);
            dfs(v);
        }
        io[u].S = t;
    }
    bool isChild(int r, int c)
    {
        return io[r].F <= io[c].F && io[c].S <= io[r].S;
    }
}

void init(int N, int M, vector<int> U, vector<int> V, vector<int> W)
{
    ::N = N, ::M = M, ::K = N - 1;
    for (int i = 0; i < N; i++)
        node[i] = dsu[i] = chain[i][0] = chain[i][1] = i, rk[i] = 1;

    for (int i = 0; i < M; i++)
        edge.emplace_back(make_pair(W[i], pii(U[i], V[i])));
    sort(edge.begin(), edge.end());
    for (auto [w, p] : edge)
    {
        auto [u, v] = p;
        merge(u, v, u, v, w);
    }
    pre[K][0] = K;
    dfs(K);
    for (int p = 0; p < 19; p++)
        for (int i = 0; i <= K; i++)
            pre[i][p + 1] = pre[pre[i][p]][p];
}

int getMinimumFuelCapacity(int X, int Y)
{
    int lca = X, ans = 2e9;
    for (int p = 19; p >= 0; p--)
        if (!isChild(pre[lca][p], Y))
            lca = pre[lca][p];
    if (!isChild(lca, Y))
        lca = pre[lca][0];

    ans = dp[lca];
    return (ans > 1.5e9 ? -1 : ans);
}

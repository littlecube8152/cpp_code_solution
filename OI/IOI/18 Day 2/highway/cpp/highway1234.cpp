#include "highway.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

namespace
{
    int N, M;
    ll D, bfsD, dis[90000];
    vector<pii> E[90000], tE[90000];
    vector<int> tree;
    int vis[90000], sz[90000], pre[90000];
};

void dfs(int u)
{
    vis[u] = sz[u] = 1;
    for (auto [v, i] : E[u])
        if (!vis[v])
        {
            dis[v] = dis[u] + 1;
            dfs(v);
            sz[u] += sz[v];
        }
    tree.emplace_back(u);
}

int search(vector<int> v)
{
    if (v.size() == 1)
        return v[0];
    int mid = v.size() / 2;
    vector<int> l(v.begin(), v.begin() + mid), r(v.begin() + mid, v.end()), state(M, 0);
    vector<int> child, in(N, 0);
    for (auto u : l)
        for (auto [v, i] : E[u])
        {
            state[i] = 1;
            child.emplace_back(v);
        }
    sort(child.begin(), child.end());
    child.resize(unique(child.begin(), child.end()) - child.begin());
    for (int v : child)
    {
        in[v] = 1;
        for (auto [u, i] : E[v])
            if (in[u])
                state[i] = 1;
    }
    if (ask(state) != D)
        return search(l);
    else
        return search(r);
}

void build_bfs(int r)
{
    queue<int> q;
    q.push(r);
    for (int i = 0; i < N; i++)
    {
        dis[i] = (i == r ? 0 : N);
        tE[i].clear();
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, i] : E[u])
            if (dis[v] < dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
                tE[u].emplace_back(pii(v, i));
                tE[v].emplace_back(pii(u, i));
            }
    }
}

void find_pair(int N, vector<int> U, vector<int> V, int A, int B)
{
    ::N = N;
    ::M = U.size();
    D = ask(vector<int>(M, 0));
    for (int i = 0; i < M; i++)
        E[U[i]].emplace_back(pii(V[i], i)), E[V[i]].emplace_back(pii(U[i], i));

    build_bfs(0);

    int t = 30, S = -1;
    while (t--)
    {
        vector<int> cent, subt;
        vector<int> state(M, 0);
        for (int i = 0; i < N; i++)
            if (!vis[i])
            {
                tree.clear();
                dfs(i);
                int n = sz[i], c = -1;
                for (int j : tree)
                    if (n - sz[j] <= n / 2)
                    {
                        bool valid = 1;
                        for (auto [k, _] : E[j])
                            if (n / 2 < sz[k] && sz[k] <= sz[j])
                                valid = 0;
                        if (valid)
                            c = j;
                    }
                // cerr << t << ' ' << c << '\n';
                cent.emplace_back(c);
                vis[c] = 2;
                for (auto [j, k] : E[c])
                {
                    pre[j] = k;
                    subt.emplace_back(j);
                    state[k] = 1;
                }
            }
        ll nD = ask(state);
        for (int i = 0; i < N; i++)
            if (vis[i] == 1)
                vis[i] = 0;
        if (nD == D)
            continue;
        cerr << "S is in some subtree\n";
        int rS = search(subt);
        ll bfsD = ask(state);
        cerr << "root of subtree is " << rS << '\n';
        tree.clear();
        dis[rS] = 0;
        dfs(rS);
        state = vector<int>(M, 0);
        for (int i : tree)
            for (auto [j, k] : E[i])
                if (vis[j] == 1)
                    state[k] = 1;
        ll dist = (ask(state) - D) / (B - A);
        vector<int> vD;
        for (int i : tree)
            if (dis[i] == dist)
                vD.emplace_back(i);
        S = search(vD);
        cerr << "S is " << S << '\n';
        break;
    }
    assert(t > 0);
    tree.clear();
    for (int i = 0; i < N; i++)
        vis[i] = 0;
    dis[S] = 0;
    dfs(S);
    vector<int> vD;
    for (int i : tree)
        if (dis[i] * A == D)
            vD.emplace_back(i);
    int T = search(vD);
    cerr << "T is " << T << '\n';
    answer(S, T);
}

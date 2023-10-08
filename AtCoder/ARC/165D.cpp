#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), \
             cin.tie(0), cout.tie(0)
using namespace std;

int N, M, A[2005], B[2005], C[2005], D[2005], dsu[2005], fin[2005], vis[2005], adj[2005][2005];
vector<int> E[2005], R[2005], order;
vector<pii> len;
bool fail = 0;

int find(int u)
{
    return dsu[u] == u ? u : dsu[u] = find(dsu[u]);
}

bool change = 0;

void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    change = 1;
    dsu[find(u)] = find(v);
}

void dfs(int u)
{
    vis[u] = 1;
    for (auto v : E[u])
        if (!vis[v])
            dfs(v);
    order.emplace_back(u);
}

void dfscc(int u)
{
    vis[u] = 0;
    for (auto v : R[u])
        if (vis[v])
        {
            merge(u, v);
            dfscc(v);
        }
}

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dsu[i] = i;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        len.emplace_back(pii(i, 0));
    }
    bool remain = 1;
    while (remain)
    {
        change = 0;
        vector<pii> edge, nxt;
        for (int i = 1; i <= N; i++)
            for (auto j : E[i])
                if (find(i) != find(j))
                {
                    edge.emplace_back(pii(find(i), find(j)));
                    adj[find(i)][find(j)] = 1;
                }

        for (int i = 1; i <= N; i++)
            vis[i] = 0, E[i].clear(), R[i].clear();
        order.clear();
        for (auto [u, v] : edge)
            E[u].emplace_back(v), R[v].emplace_back(u);

        for (auto [i, l] : len)
        {
            if (C[i] + l > D[i])
            {
                fail = 1;
                goto ono;
            }
            else if (A[i] + l > B[i])
                ;
            else
            {
                int u = find(A[i] + l), v = find(C[i] + l);
                nxt.emplace_back(pii(i, l));
                if (!adj[u][v])
                {
                    E[u].emplace_back(v);
                    R[v].emplace_back(u);
                    adj[u][v] = 1;
                }
            }
        }
        for (int i = 1; i <= N; i++)
            if (dsu[i] == i && !vis[i])
                dfs(i);
        reverse(all(order));
        for (auto i : order)
            if (vis[i])
                dfscc(i);
        remain = 0;
        for (auto &[i, l] : nxt)
            while (A[i] + l <= B[i] && C[i] + l <= D[i] && find(A[i] + l) == find(C[i] + l))
                l++, remain = 1;
        len = nxt;
        if (!change)
            break;
    }
ono:
    cout << (fail ? "No\n" : "Yes\n");
}
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int P = 17;

int N, M;
ll dis[17][100005], h[17][100005], d[4000005], p[100005], sz[100005];
vector<pll> tree[100005], bfs[100005], E[4000005];
bool vis[100005];

void find_sz(int u, int r)
{
    sz[u] = 1;
    vis[u] = 1;
    bfs[r].emplace_back(pll(u, 0));
    for (auto [v, w] : tree[u])
        if (!vis[v])
        {
            find_sz(v, r);
            sz[u] += sz[v];
        }
}

void dfs(int u, int r, int l)
{
    vis[u] = 1;
    h[l][u] = r;
    bfs[r].emplace_back(pll(dis[l][u], u));
    for (auto [v, w] : tree[u])
        if (!vis[v])
        {
            dis[l][v] = dis[l][u] + w;
            dfs(v, r, l);
        }
}

void cdec(int r, int l)
{
    find_sz(r, r);
    int c = -1;
    for (auto [i, _] : bfs[r])
    {
        bool flag = (sz[r] - sz[i] <= sz[r] / 2);
        for (auto [j, _] : tree[i])
            if (sz[i] >= sz[j] && sz[j] > sz[r] / 2)
                flag = 0;
        if (flag)
            c = i;
    }
    for (auto [i, _] : bfs[r])
        sz[i] = vis[i] = 0;
    bfs[r].clear();

    dis[l][c] = 0;
    dfs(c, c, l);
    sort(bfs[c].begin(), bfs[c].end());
    for (int i = 0; i < bfs[c].size(); i++)
    {
        E[(l * 2 + 1) * (N + 1) + bfs[c][i].S].emplace_back(pll(bfs[c][i].S, 0));
        E[bfs[c][i].S].emplace_back(pll((l * 2 + 2) * (N + 1) + bfs[c][i].S, 0));
        if (i)
        {
            E[(l * 2 + 1) * (N + 1) + bfs[c][i].S].emplace_back(pll((l * 2 + 1) * (N + 1) + bfs[c][i - 1].S, 0));
            E[(l * 2 + 2) * (N + 1) + bfs[c][i - 1].S].emplace_back(pll((l * 2 + 2) * (N + 1) + bfs[c][i].S, 0));
        }
    }
    for (auto [_, i] : bfs[c])
        vis[i] = 0;
    vis[c] = 1;
    for (auto [u, w] : tree[c])
        if (!vis[u])
            cdec(u, l + 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    for (int i = 1; i <= N; i++)
    {
        cin >> d[i];
        tree[p[i]].emplace_back(pll(i, d[i]));
        tree[i].emplace_back(pll(p[i], d[i]));
    }
    for (int l = 0; l < P; l++)
        for (int i = 0; i <= N; i++)
            h[l][i] = -1;
    cdec(0, 0);
    int pf = (P * 2 + 1) * (N + 1);
    for (int i = 1; i <= M; i++)
    {
        int u, du, v, dv, w;
        cin >> u >> du >> v >> dv >> w;
        for (int l = 0; l < P; l++)
            if (h[l][u] != -1)
            {
                auto iter = upper_bound(bfs[h[l][u]].begin(), bfs[h[l][u]].end(), pll(du - dis[l][u], 1e9));
                if (iter == bfs[h[l][u]].begin())
                    continue;
                --iter;
                E[pf + 1].emplace_back(pll((l * 2 + 1) * (N + 1) + iter->S, w));
                E[(l * 2 + 2) * (N + 1) + iter->S].emplace_back(pll(pf + 2, w));
            }
        for (int l = 0; l < P; l++)
            if (h[l][v] != -1)
            {
                auto iter = upper_bound(bfs[h[l][v]].begin(), bfs[h[l][v]].end(), pll(dv - dis[l][v], 1e9));
                if (iter == bfs[h[l][v]].begin())
                    continue;
                --iter;
                E[pf + 2].emplace_back(pll((l * 2 + 1) * (N + 1) + iter->S, 0));
                E[(l * 2 + 2) * (N + 1) + iter->S].emplace_back(pll(pf + 1, 0));
            }
        pf += 2;
    }
    for (int i = 0; i <= pf; i++)
        d[i] = 1e18;
    d[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(pll(0, 1));
    while(!pq.empty())
    {
        auto [ds, u] = pq.top();
        pq.pop();
        if(d[u] > ds)
            continue;
        for(auto [v, w] : E[u])
            if(ds + w < d[v])
            {
                d[v] = ds + w;
                pq.push(pll(d[v], v));
            }
    }
    for (int i = 0; i <= N; i++)
        cout << (d[i] >= 1e18 ? -1 : d[i]) << '\n';
}
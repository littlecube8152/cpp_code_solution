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

int N, M, ans = 2e9, dsu[200005], vis[200005];
vector<int> E[200005];
vector<pair<int, pii>> e;

int find(int u)
{
    return dsu[u] == u ? u : dsu[u] = find(dsu[u]);
}

void dfs(int u, int c = 1)
{
    vis[u] = c;
    for (auto v : E[u])
        if(!vis[v])
            dfs(v, c ^ 3);
}

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dsu[i] = i;
    for (int i = 1; i <= M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.emplace_back(w, pii(u, v));
        E[u].emplace_back(w);
        E[v].emplace_back(w);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(all(E[i]));
        if (E[i].size() >= 2)
            ans = min(ans, E[i][0] + E[i][1]);
        E[i].clear();
    }
    sort(e.begin(), e.end());
    for (auto [w, p] : e)
    {
        auto [u, v] = p;
        if (find(u) != find(v))
        {
            dsu[find(u)] = find(v);
            E[u].emplace_back(v);
            E[v].emplace_back(u);
        }
    }
    dfs(1);
    for (auto [w, p] : e)
    {
        auto [u, v] = p;
        if (vis[u] == vis[v])
            ans = min(ans, w);
    }
        
    cout << ans << '\n';
}
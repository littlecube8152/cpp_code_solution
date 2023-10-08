/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, q, vis[200005], scc[200005], sdx;
ll ans[200005], dis[200005];
vector<int> order;
vector<pll> E[200005], rE[200005];

void dfs(int u)
{
    vis[u] = 1;
    for (auto [v, w] : E[u])
        if (!vis[v])
            dfs(v);
    order.emplace_back(u);
}

ll safemod(ll a, ll m)
{
    return (m == 0 ? a : a % m);
}

void solve(int u, int s, ll &mul)
{
    scc[u] = s;
    vis[u] = 1;
    for (auto [v, w] : rE[u])
        if (!vis[v])
        {
            dis[v] = safemod(dis[u] + w, mul);
            solve(v, s, mul);
        }
        else if(scc[v] == scc[u])
            mul = __gcd(abs((dis[u] + w) - dis[v]), mul);
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        E[u].emplace_back(pll(v, l));
        rE[v].emplace_back(pll(u, l));
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);

    reverse(order.begin(), order.end());

    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    for (int i : order)
        if (!vis[i])
        {
            ++sdx;
            solve(i, sdx, ans[sdx]);
        }
    // for (int i = 1; i <= n; i++)
    //     cout << scc[i] << ' ' << ans[i] << '\n';
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ll u, s, t;
        cin >> u >> s >> t;
        cout << ((t - s) % __gcd(t, ans[scc[u]]) == 0 ? "YES\n" : "NO\n");
    }
}

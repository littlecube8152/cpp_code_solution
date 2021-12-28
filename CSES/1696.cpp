/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, m, E, ans, s, t, adjptr[1005], vis[1005], dis[1005];
// {from, to, capacity}
vector<pair<pii, ll>> e;
vector<int> adj[1005];

bool bfs()
{
    for (int i = 1; i <= 1002; i++)
        vis[i] = 0, dis[i] = 1002 + 1;

    queue<int> q;
    q.push(s);
    vis[s] = 1, dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = e[adj[u][i]].F.S;
            if (!vis[v] && e[adj[u][i]].S > 0)
            {
                dis[v] = dis[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    if (dis[t] > 1002)
        return false;
    return true;
}

ll dfs(int k, ll flow)
{
    if (flow <= 0)
        return 0;
    if (k == t)
        return flow;
    for (; adjptr[k] < adj[k].size(); adjptr[k]++)
    {
        int d = adj[k][adjptr[k]];
        if (e[d].S <= 0)
            continue;
        else if (vis[e[d].F.S])
            continue;
        else if (dis[e[d].F.S] != dis[k] + 1)
            continue;
        vis[e[d].F.S] = 1;
        ll f = dfs(e[d].F.S, min(flow, e[d].S));
        if (f > 0)
        {
            e[d].S -= f;
            e[d ^ 1].S += f;
            return f;
        }
    }
    return 0;
}

signed main()
{
    //fast;
    cin >> n >> m >> E;
    for (int i = 1; i <= E; i++)
    {
        ll u, v;
        cin >> u >> v;
        u += 1;
        v += 501;
        adj[u].emplace_back(e.size());
        e.emplace_back(pair<pii, ll>{{u, v}, 1});
        adj[v].emplace_back(e.size());
        e.emplace_back(pair<pii, ll>{{v, u}, 0});
    }
    for (int i = 1; i <= n; i++)
    {
        adj[1].emplace_back(e.size());
        e.emplace_back(pair<pii, ll>{{1, i + 1}, 1});
        adj[i + 1].emplace_back(e.size());
        e.emplace_back(pair<pii, ll>{{i + 1, 1}, 0});
    }
    for (int i = 1; i <= m; i++)
    {
        adj[501 + i].emplace_back(e.size());
        e.emplace_back(pair<pii, ll>{{501 + i, 1002}, 1});
        adj[1002].emplace_back(e.size());
        e.emplace_back(pair<pii, ll>{{1002, 501 + i}, 0});
    }
    s = 1, t = 1002;
    while (bfs())
    {
        for (int i = 1; i <= 1002; i++)
            adjptr[i] = 0;
        while (true)
        {
            for (int i = 1; i <= 1002; i++)
                vis[i] = 0;
            ll f = dfs(s, 1e10);
            ans += f;
            //cout << f << '\n';
            if (f == 0)
                break;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < adj[i + 1].size(); j++)
        {
            int k = e[adj[i + 1][j]].F.S;
            if (e[adj[i + 1][j]].S == 0 && k > 1)
                cout << i << " " << k - 501 << '\n';
        }
}

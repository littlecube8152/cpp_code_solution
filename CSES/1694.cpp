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

ll V, E;

template <int V>
struct dinic
{
    const ll INF = 1e18;
    ll adjptr[V + 1], dis[V + 1], vis[V + 1], s, t, ans;
    struct edge
    {
        ll u, v, cap;
    };
    vector<edge> e;
    vector<int> adj[V + 1];

    bool bfs()
    {
        for (int i = 1; i <= V; i++)
            dis[i] = (i == s ? 0 : V + 1);
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto id : adj[u])
            {
                auto [_, v, cap] = e[id];
                if (dis[v] > V && cap > 0)
                {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis[t] <= V;
    }

    vector<pii> find_cut()
    {
        vector<pii> cut;
        bfs();
        for (int i = 0; i < e.size(); i += 2)
            if (dis[e[i].u] <= V && dis[e[i].v] > V)
                cut.emplace_back(pii(e[i].u, e[i].v));
        return cut;
    }
    ll dfs(int u, ll flow)
    {
        if (u == t || !flow)
            return flow;
        for (; adjptr[u] < (int)adj[u].size(); adjptr[u]++)
        {
            int d = adj[u][adjptr[u]];
            auto [_, v, cap] = e[d];
            if (cap <= 0 || vis[v] || dis[v] != dis[u] + 1)
                continue;
            vis[v] = 1;
            ll f = dfs(v, min(flow, cap));
            if (f)
            {
                e[d].cap -= f, e[d ^ 1].cap += f;
                return f;
            }
        }
        return 0;
    }
    void add_edge(int u, int v, ll c)
    {
        adj[u].emplace_back(e.size());
        e.emplace_back(edge{u, v, c});
        adj[v].emplace_back(e.size());
        e.emplace_back(edge{v, u, 0});
    }
    ll flow(int S, int T)
    {
        s = S, t = T;
        for (int i = 0; i < (int)e.size(); i += 2)
            e[i].cap = e[i].cap + e[i ^ 1].cap, e[i ^ 1].cap = 0;
        while (bfs())
        {
            for (int i = 1; i <= V; i++)
                adjptr[i] = 0, vis[i] = 0;
            ll f = 1;
            while (f)
                ans += (f = dfs(s, INF));
        }
        return ans;
    }
};

signed main()
{
    // fast;
    cin >> V >> E;
    dinic<501> flow;
    for (int i = 1; i <= E; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }

    cout << flow.flow(1, V) << '\n';
}

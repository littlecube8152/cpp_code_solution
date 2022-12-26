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
#define int long long
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

template <typename Cap, int V>
struct dinic
{
    const Cap INF = numeric_limits<Cap>::max() / 2;
    int adjptr[V + 1], vis[V + 1], dis[V + 1], s, t;
    Cap ans = 0;
    // {from, to, capacity}
    vector<pair<pair<int, int>, Cap>> e;
    vector<int> adj[V + 1];

    bool bfs()
    {
        for (int i = 1; i <= V; i++)
            vis[i] = 0, dis[i] = V + 1;

        queue<int> q;
        q.push(s);
        vis[s] = 1, dis[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = e[adj[u][i]].first.second;
                if (!vis[v] && e[adj[u][i]].second > 0)
                {
                    dis[v] = dis[u] + 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        if (dis[t] > V)
            return false;
        return true;
    }

    vector<pair<int, int>> find_cut()
    {
        vector<pair<int, int>> cut;
        for (int i = 1; i <= V; i++)
            vis[i] = 0, dis[i] = V + 1;

        queue<int> q;
        q.push(s);
        vis[s] = 1, dis[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = e[adj[u][i]].first.second;
                if (!vis[v] && e[adj[u][i]].second > 0)
                {
                    dis[v] = dis[u] + 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        for (int u = 1; u <= V; u++)
            if (vis[u])
                for (int i = 0; i < (int)adj[u].size(); i++)
                {
                    int v = e[adj[u][i]].first.second;
                    if (!vis[v] && adj[u][i] % 2 == 0)
                        cut.emplace_back(pair<int, int>{u, v});
                }
        return cut;
    }

    Cap dfs(int k, Cap flow)
    {
        if (flow <= 0)
            return 0;
        if (k == t)
            return flow;
        for (; adjptr[k] < (int)adj[k].size(); adjptr[k]++)
        {
            int d = adj[k][adjptr[k]];
            if (e[d].second <= 0)
                continue;
            else if (vis[e[d].first.second])
                continue;
            else if (dis[e[d].first.second] != dis[k] + 1)
                continue;
            vis[e[d].first.second] = 1;
            Cap f = dfs(e[d].first.second, min(flow, e[d].second));
            if (f > 0)
            {
                e[d].second -= f;
                e[d ^ 1].second += f;
                return f;
            }
        }
        return 0;
    }

    void add_edge(int u, int v, Cap c)
    {
        adj[u].emplace_back(e.size());
        e.emplace_back(pair<pair<int, int>, Cap>{{u, v}, c});
        adj[v].emplace_back(e.size());
        e.emplace_back(pair<pair<int, int>, Cap>{{v, u}, 0});
    }

    Cap flow(int S, int T)
    {
        this->s = S;
        this->t = T;
        while (bfs())
        {
            for (int i = 1; i <= V; i++)
                adjptr[i] = 0;
            while (true)
            {
                for (int i = 1; i <= V; i++)
                    vis[i] = 0;
                Cap f = dfs(s, INF);
                ans += f;
                if (f == 0)
                    break;
            }
        }
        return ans;
    }
};

int N, M, adj[55][55];
vector<int> ans;

signed main()
{
    // fast;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int w, l;
        cin >> w >> l;
        adj[w][l] = w;
        adj[l][w] = w;
    }
    for (int i = 1; i <= N; i++)
    {
        dinic<int, 2500> flow;
        int idx = N, most = 0;
        for (int u = 1; u <= N; u++)
            if (u != i && (adj[i][u] == 0 || adj[i][u] == i))
                most++;
        for (int u = 1; u <= N; u++)
            for (int v = u + 1; v <= N; v++)
            {
                idx++;
                if (adj[u][v])
                    flow.add_edge(idx, adj[u][v], 1);
                else if (u == i)
                    flow.add_edge(idx, u, 1);
                else if (v == i)
                    flow.add_edge(idx, v, 1);
                else
                {
                    flow.add_edge(idx, u, 1);
                    flow.add_edge(idx, v, 1);
                }
            }
        for (int u = N + 1; u <= idx; u++)
            flow.add_edge(idx + 1, u, 1);
        for (int u = 1; u <= N; u++)
            flow.add_edge(u, idx + 2, (u == i ? most : most - 1));
        if (flow.flow(idx + 1, idx + 2) == N * (N - 1) / 2)
            ans.emplace_back(i);
    }
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <int V>
struct dinic
{
    const ll INF = 4e18;
    int adjptr[V + 1], dis[V + 1], s, t;
    bool vis[V + 1];
    ll ans = 0;
    // {from, to, capacity}
    vector<pair<pair<int, int>, ll>> e;
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
    ll dfs(int k, ll flow)
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
            ll f = dfs(e[d].first.second, min(flow, e[d].second));
            if (f > 0)
            {
                e[d].second -= f;
                e[d ^ 1].second += f;
                return f;
            }
        }
        return 0;
    }
    void add_edge(int u, int v, ll c)
    {
        adj[u].emplace_back(e.size());
        e.emplace_back(pair<pair<int, int>, ll>{{u, v}, c});
        adj[v].emplace_back(e.size());
        e.emplace_back(pair<pair<int, int>, ll>{{v, u}, c});
    }
    ll flow(int S, int T)
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
                ll f = dfs(s, INF);
                ans += f;
                if (f == 0)
                    break;
            }
        }
        return ans;
    }
};

dinic<110> flow;

int N, p0;
ll s[105][2], v[105][2], ans;
// s * v
signed main()
{
    cin >> N >> p0;
    
    for (int j = 0; j <= 1; j++)
        for (int i = 1; i <= N; i++)
            cin >> s[i][j];
    for (int j = 0; j <= 1; j++)
        for (int i = 1; i <= N; i++)
            cin >> v[i][j];

    for (int i = 1; i <= N; i++)
    {
        ans += p0 * v[i][0];
        flow.add_edge(N + 1, i, p0 * v[i][0] * 2);
        ans += p0 * v[i][1];
        flow.add_edge(i, N + 2, p0 * v[i][1] * 2);
    }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
        {
            ll w0 = max(s[i][0] * v[j][0], s[j][0] * v[i][0]);
            ll w1 = max(s[i][1] * v[j][1], s[j][1] * v[i][1]);
            flow.add_edge(N + 1, i, w0);
            flow.add_edge(N + 1, j, w0);
            flow.add_edge(i, j, w0 + w1);
            flow.add_edge(i, N + 2, w1);
            flow.add_edge(j, N + 2, w1);
            ans += w0 + w1;
        }
    cerr << ans << '\n';
    ll f = flow.flow(N + 1, N + 2);
    cerr << f << '\n';
    cout << ans - f / 2 << '\n';
}
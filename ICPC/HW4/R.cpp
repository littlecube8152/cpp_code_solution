#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, p[100005][20], d[100005], dis[100005], vis[100005], t;
vector<int> E[100005];
vector<pii> e;
pii io[100005];

void bfs(int r)
{
    queue<int> q;
    vis[r] = 1;
    q.emplace(r);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : E[u])
            if (!vis[v])
            {
                p[v][0] = u;
                vis[v] = 1;
                q.push(v);
            }
            else if (v != p[u][0] && u < v)
                e.emplace_back(u, v);
    }
}

void dfs(int u)
{
    io[u].F = ++t;
    for (auto v : E[u])
        if (v != p[u][0])
        {
            dis[v] = dis[u] + 1;
            dfs(v);
        }
    io[u].S = t;
}

bool ischild(int r, int c)
{
    return io[r].F <= io[c].F && io[c].F <= io[r].S;
}

int lca(int u, int v)
{
    for (int k = 19; k >= 0; k--)
        if(!ischild(p[u][k], v))
            u = p[u][k];
    if(!ischild(u, v))
        u = p[u][0];
    return u;
}

vector<pii> cyc[100005];

signed main()
{
    cin >> N;
    for (int i = 1; i <= 2 * N - 3; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
        d[u]++, d[v]++;
    }
    for (int i = 1; i <= N; i++)
        if (d[i] >= 3 && !vis[i])
            bfs(i);
    for (int i = 1; i <= N; i++)
        E[i].clear();
    for (int i = 1; i <= N; i++)
        E[p[i][0]].emplace_back(i);
    dfs(0);
    for (int j = 0; j + 1 < 20; j++)
        for (int i = 1; i <= N; i++)
            p[i][j + 1] = p[p[i][j]][j];
    for (auto [u, v] : e)
    {
        int l = dis[u] + dis[v] - 2 * dis[lca(u, v)];
        cyc[l].emplace_back(u, v);
    }
    for (int i = 2; i < N - 1; i++)
        if(cyc[i].size() >= 2)
        {
            cout << i + 1 << '\n';
            cyc[i].resize(2);
            for (auto [u, v] : cyc[i])
            {
                int l = lca(u, v);
                vector<int> f, s;
                while(u != l)
                {
                    f.emplace_back(u);
                    u = p[u][0];
                }
                while(v != l)
                {
                    s.emplace_back(v);
                    v = p[v][0];
                }
                reverse(s.begin(), s.end());
                for (auto i : f)
                    cout << i << ' ';
                cout << l;
                for (int i : s)
                    cout << ' ' << i;
                cout << '\n';
            }
            break;
        }
}
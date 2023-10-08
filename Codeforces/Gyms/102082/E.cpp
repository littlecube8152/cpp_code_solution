#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int n, m, O[105][105], G[105][105], deg[105], vis[105], tar[105];
vector<int> sing, odd;
vector<pii> sol;

void fail()
{
    cout << -1 << '\n';
    exit(0);
}

void add(int u, int v)
{
    G[u][v] ^= 1;
    G[v][u] ^= 1;
}

int path(int u)
{
    vis[u] = 1;
    if (tar[u])
        return u;
    for (int v = 1; v <= n; v++)
        if (!vis[v] && !O[u][v])
        {
            add(u, v);
            int r = path(v);
            if (r)
                return r;
            add(u, v);
        }
    return 0;
}

vector<int> cc;
int dfs(int u)
{
    cc.emplace_back(u);
    vis[u] = 1;
    for (int v = 1; v <= n; v++)
        if (!vis[v] && G[u][v])
            dfs(v);
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        O[u][v] = O[v][u] = 1;
        add(u, v);
        deg[u]++, deg[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            sing.emplace_back(i);
        else if (deg[i] % 2 == 1)
            odd.emplace_back(i);
    int p = sing.size(), q = odd.size();
    if (p && q)
    {
        for (int i = 0; i + 1 < p; i++)
            add(sing[i], sing[i + 1]);
        for (int i = 0; i < q; i += 2)
            add(sing[0], odd[i]), add(sing[p - 1], odd[i + 1]);
    }
    else if (!p && q)
    {
        for (int i : odd)
            tar[i] = 1;
        for (int i : odd)
            if (tar[i])
            {
                tar[i] = 0;
                fill(vis + 1, vis + 1 + n, 0);
                int res = path(i);
                if (!res)
                    fail();
                tar[res] = 0;
            }
    }
    else if (p && !q)
    {
        if (p == 1)
        {
            int u, v;
            for (u = 1; u <= n; u++)
                for (v = u + 1; v <= n; v++)
                    if (deg[u] && deg[v] && !O[u][v])
                        goto yay;
            fail();
        yay:
            add(u, sing[0]);
            add(v, sing[0]);
            add(u, v);
        }
        if (p == 2)
        {
            int u, v;
            for (u = 1; u <= n; u++)
                if (deg[u])
                    break;
            for (v = u + 1; v <= n; v++)
                if (deg[v])
                    goto oyes;
            fail();
        oyes:
            add(u, sing[0]);
            add(v, sing[0]);
            add(u, sing[1]);
            add(v, sing[1]);
        }
        else
        {
            for (int i = 0; i < p; i++)
                add(sing[i], sing[(i + 1) % p]);
        }
    }

    vector<int> cur;
    fill(vis + 1, vis + 1 + n, 0);
    dfs(1);
    cur = cc;
    for (int i = 1; i <= n; i++)
        if(!vis[i])
        {
            cc.clear();
            dfs(i);
            add(cur[0], cc[0]);
            add(cur[0], cc[1]);
            add(cur[1], cc[0]);
            add(cur[1], cc[1]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if(G[i][j] ^ O[i][j])
                sol.emplace_back(pii(i, j));
    cout << sol.size() << '\n';
    for (auto [i, j] : sol)
        cout << i << ' ' << j << '\n';
}
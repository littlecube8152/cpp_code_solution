#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

ll n, m, k, dis[2][2005], pre[2005], newdis[2005], Nweight[2005], Eweight[8005], worseEdge[8005], adj[2005][2005], worseAdj[2005][2005];
vector<pii> edge;
vector<ll> village[8005];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> Nweight[i];
    edge.resize(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[i] = {x, y};
        village[i].resize(k + 1);
        village[i][0] = 0;
        for (int j = 1; j <= k; j++)
        {
            cin >> village[i][j];
            village[i][j] += village[i][j - 1];
            worseEdge[i] = min(village[i][j - 1], worseEdge[i]);
        }
        worseAdj[x][y] = worseAdj[y][x] = worseEdge[i];
        adj[x][y] = adj[y][x] = Eweight[i] = village[i][k];
    }
    for (int i = 1; i <= n; i++)
        dis[0][i] = min(0LL, Nweight[i]);
    for (int i = 1; i <= n + 1; i++)
    {
        for (int u = 1; u <= n; u++)
            dis[i % 2][u] = dis[(i - 1) % 2][u];
        for (int j = 1; j <= m; j++)
        {
            ll u = edge[j].F, v = edge[j].S, w = Eweight[j];
            if (dis[i % 2][u] <= dis[(i - 1) % 2][v] + w + Nweight[u] && dis[(i - 1) % 2][v] + worseEdge[j] >= 0)
                pre[u] = v, dis[i % 2][u] = dis[(i - 1) % 2][v] + w + Nweight[u];
            else
                dis[i % 2][u] = dis[(i - 1) % 2][u];
            if (dis[i % 2][v] <= dis[(i - 1) % 2][u] + w + Nweight[v] && dis[(i - 1) % 2][u] + worseEdge[j] >= 0)
                pre[v] = u, dis[i % 2][v] = dis[(i - 1) % 2][u] + w + Nweight[v];
            else
                dis[i % 2][v] = dis[(i - 1) % 2][v];
        }
    }
    vector<int> negcycle;
    for (int i = 1; i <= n; i++)
        if (dis[0][i] != dis[1][i])
        {
            int u = pre[i];
            negcycle.emplace_back(i);
            while (u != i)
            {
                negcycle.emplace_back(u);
                u = pre[u];
            }
            break;
        }
    if (negcycle.size() == 0)
        cout << 0 << '\n';
    else
    {
        cout << negcycle.size() << '\n';
        for (int i : negcycle)
            cout << i << " ";
        cout << negcycle[0] << '\n';
        int ccnt = 0, vcnt = 0;
        for (int offset = 0; offset < (int)negcycle.size(); offset++)
        {
            ll dis[2005] = {0}, worse = Nweight[negcycle[offset]];
            dis[0] = Nweight[negcycle[offset]];
            for (int i = 1; i < (int)negcycle.size(); i++)
            {
                dis[i] = dis[i - 1] + adj[negcycle[(offset + i) % negcycle.size()]][negcycle[(offset + i - 1) % negcycle.size()]] + Nweight[negcycle[(offset + i) % negcycle.size()]];
                worse = min({worse, dis[i], dis[i - 1] + worseAdj[negcycle[(offset + i) % negcycle.size()]][negcycle[(offset + i - 1) % negcycle.size()]] + Nweight[negcycle[(offset + i) % negcycle.size()]]});
            }
            if (worse >= 0)
                ccnt++;
            for (int i = 1; i <= k; i++)
                if (worse - Nweight[negcycle[offset]] - village[negcycle[offset]][i - 1] >= 0)
                    vcnt++;
        }
        cout << ccnt << " " << vcnt << '\n';
    }
}
/*
5 6 1
5
-1
3
2
-5
2 1 0
3 2 -4
4 3 -3
4 2 -1
1 4 -3
5 1 3

2 2 1
-1
-1
1 2 1
2 1 1*/
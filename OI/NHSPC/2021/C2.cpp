#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

ll n, m, k, pre[1000005], newdis[1000005], Nweight[1000005];
pll dis[2][1000005];
vector<pii> edge;
vector<ll> village[1000005];
signed main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> Nweight[i];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        village[i].resize(k + 2);
        village[i][0] = x;
        village[i][k + 1] = y;
        for (int j = 1; j <= k; j++)
        {
            cin >> Nweight[n + (i - 1) * k + j];
            village[i][j] = n + (i - 1) * k + j;
        }
        for (int j = 0; j <= k; j++)
            edge.emplace_back(pii{village[i][j], village[i][j + 1]});
    }
    int oldn = n;
    n = n * (k + 1);
    for (int i = 1; i <= n; i++)
        dis[0][i].F = Nweight[i];
    for (int i = 1; i <= 2 * n + 1; i++)
    {

        for (int u = 1; u <= n; u++)
            dis[i % 2][u] = dis[(i - 1) % 2][u];
        //for (int u = 1; u <= n; u++)
        //    cout << dis[i % 2][u].F << " \n"[u == n];
        //for (int u = 1; u <= n; u++)
        //    cout << pre[u] << " \n"[u == n];
        //cout << '\n';
        for (int j = 0; j < edge.size(); j++)
        {
            ll u = edge[j].F, v = edge[j].S;
            if (dis[i % 2][v] < pll{dis[(i - 1) % 2][u].F + Nweight[v], dis[(i - 1) % 2][u].S + 1})
                pre[v] = u, dis[i % 2][v] = {dis[(i - 1) % 2][u].F + Nweight[v], dis[(i - 1) % 2][u].S + 1};
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
        reverse(negcycle.begin(), negcycle.end());
        cout << negcycle.size() + 1 << '\n';
        cout << negcycle[negcycle.size() - 1] << ' ';
        for (int i = 0; i < negcycle.size(); i++)
            cout << negcycle[i] << " \n"[negcycle.size() == i + 1];

        int ccnt = 0, vcnt = 0;
        for (int offset = 0; offset < (int)negcycle.size(); offset++)
        {
            ll dis[400005] = {0}, worse = Nweight[negcycle[offset]];
            dis[0] = Nweight[negcycle[offset]];
            for (int i = 1; i < (int)negcycle.size(); i++)
            {
                dis[i] = dis[i - 1] + Nweight[negcycle[(offset + i) % negcycle.size()]];
                worse = min({worse, dis[i]});
            }
            if (worse >= 0 && negcycle[offset] <= oldn)
                ccnt++;
            else if (worse >= 0)
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
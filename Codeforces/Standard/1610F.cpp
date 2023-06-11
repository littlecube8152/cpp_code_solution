/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, k, idx[100005], vis[100005], ans[100005], d[100005], tot;
vector<pii> one[100005], two[100005], bip[100005];
vector<int> euler;
vector<int> path[100005];

int dfs(int u, vector<pii> E[])
{
    for (int &i = idx[u]; i < E[u].size(); i++)
    {
        auto [v, j] = E[u][i];
        if (vis[abs(j)])
            continue;
        vis[abs(j)] = 1;
        ans[abs(j)] = (j > 0 ? 1 : 2);
        d[u]--, d[v]--;
        euler.emplace_back(abs(j));
        return dfs(v, E);
    }
    return u;
}

void color(int u, int dir)
{
    for (int &i = idx[u]; i < bip[u].size(); i++)
    {
        auto [v, j] = bip[u][i];
        if (vis[abs(j)])
            continue;
        j *= dir;
        vis[abs(j)] = 1;
        if (j < 0)
            for (int node : path[abs(j)])
                ans[node] ^= 3;
        d[u]--, d[v]--;
        color(v, dir);
        dir *= -1;
    }
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 1)
        {
            one[u].emplace_back(pii(v, i));
            one[v].emplace_back(pii(u, -i));
        }
        else
        {
            two[u].emplace_back(pii(v, i));
            two[v].emplace_back(pii(u, -i));
        }
    }
    for (int i = 1; i <= n; i++)
        d[i] = one[i].size();
    for (int i = 1; i <= n; i++)
        if (d[i] % 2 == 1)
        {
            tot += 2;
            int j = dfs(i, one);
            path[++k].swap(euler);
            bip[i].emplace_back(pii(j, k));
            bip[j].emplace_back(pii(i, -k));
            
        }
    for (int i = 1; i <= n; i++)
        while (d[i])
            i == dfs(i, one);

    for (int i = 1; i <= n; i++)
        d[i] = two[i].size();
    for (int i = 1; i <= n; i++)
        idx[i] = 0;

    for (int i = 1; i <= n; i++)
        if (d[i] % 2 == 1)
        {
            int j = dfs(i, two);
            path[++k].swap(euler);
            bip[i].emplace_back(pii(j, k));
            bip[j].emplace_back(pii(i, -k));
        }
    for (int i = 1; i <= n; i++)
        while (d[i])
            dfs(i, two);

    for (int i = 1; i <= n; i++)
        vis[i] = idx[i] = 0;

    for (int i = 1; i <= n; i++)
        d[i] = bip[i].size();
    for (int i = 1; i <= n; i++)
        if (d[i])
            color(i, 1);

    cout << tot << '\n';
    for (int i = 1; i <= m; i++)
        cout << ans[i];
    cout << '\n';
}
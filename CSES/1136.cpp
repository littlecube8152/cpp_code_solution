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

ll n, q, pre[200005][25], t, val[200005];
vector<int> E[200005];
pii io[200005];

void dfs(int k)
{
    io[k].F = ++t;
    for (int i : E[k])
        if (pre[k][0] != i)
        {
            pre[i][0] = k;
            dfs(i);
        }
    io[k].S = ++t;
}

int lca(int u, int v)
{
    int lca = u;
    for (int p = 20; p >= 0; p--)
        if (pre[lca][p] != 0 && !(io[pre[lca][p]].F <= io[v].F && io[v].S <= io[pre[lca][p]].S))
            lca = pre[lca][p];
    if (!(io[lca].F <= io[v].F && io[v].S <= io[lca].S))
        lca = pre[lca][0];
    return lca;
}

void dfs2(int k)
{
    for (int i : E[k])
        if (pre[k][0] != i)
        {
            dfs2(i);
            val[k] += val[i];
        }
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i <= n; i++)
            pre[i][p] = pre[pre[i][p - 1]][p - 1];
    while (q--)
    {
        int u, v, l;
        cin >> u >> v;
        l = lca(u, v);
        val[u]++, val[v]++, val[l]--, val[pre[l][0]]--;
    }
    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << val[i] << " \n"[i == n];
}

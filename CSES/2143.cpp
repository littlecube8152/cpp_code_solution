/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, m, q, scc[50005], scccnt, vis[50005];
bitset<50005> b[50005];
vector<int> E[50005], rE[50005], nE[50005], topo;

void dfs(int k)
{
    vis[k] = 1;
    for (int i : E[k])
        if (!vis[i])
            dfs(i);
    topo.emplace_back(k);
}

void dfs2(int k, int idx)
{
    vis[k] = 2;
    for (int i : rE[k])
        if (vis[i] == 1)
            dfs2(i, idx);
    scc[k] = idx;
}

signed main()
{
    fast;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        b[i][i] = 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        rE[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);

    reverse(topo.begin(), topo.end());

    for (int i : topo)
        if (vis[i] == 1)
            dfs2(i, ++scccnt);

    for (int i = 1; i <= n; i++)
        for (int j : rE[i])
            if (scc[i] != scc[j])
                nE[scc[i]].emplace_back(scc[j]);

    for (int i = scccnt; i >= 1; i--)
        for (int j : nE[i])
            b[j] |= b[i];

    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << (b[scc[u]][scc[v]] ? "YES\n" : "NO\n");
    }
}

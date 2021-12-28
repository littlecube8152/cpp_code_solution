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
const ll MOD = 1000000007;
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll num[2] = {1, 3}, base = 5;
ll pbase[200005];
ll t, n, pre[100005], sz[100005], ans[2];
pll h[100005];
vector<int> E[100005];

void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            sz[k] += sz[i];
        }
    sort(E[k].begin(), E[k].end(), [&](int i1, int i2)
         { return h[i1] < h[i2]; });
    for (int i : E[k])
        if (i != pre[k])
        {
            h[k].S = (h[k].S + pbase[h[k].F] * h[i].S) % MOD;
            h[k].F += h[i].F;
        }
    h[k] = {h[k].F + 1, (h[k].S + pbase[h[k].F] * num[1]) % MOD};
}

ll hashing()
{
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    return h[1].S;
}

signed main()
{
    fast;
    cin >> t;
    pbase[0] = 1;
    for (int i = 1; i <= 200000; i++)
        pbase[i] = pbase[i - 1] * base % MOD;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            pre[i] = 0, sz[i] = 1, h[i] = {1, num[0]}, E[i].clear();
        ans[0] = hashing();
        for (int i = 1; i <= n; i++)
            pre[i] = 0, sz[i] = 1, h[i] = {1, num[0]}, E[i].clear();
        ans[1] = hashing();
        if(ans[0] == ans[1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

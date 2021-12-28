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

ll n, q, pre[200005], t, val[200005], bit[200005];
vector<int> E[200005];
pii io[200005];

void modify(int pos, ll val)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] += val;
}

ll query(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void dfs(int k)
{
    io[k].F = ++t;
    for (int i : E[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dfs(i);
        }
    io[k].S = t;
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        modify(io[i].F, val[i]);
        modify(io[i].S + 1, -val[i]);
    }
    while (q--)
    {
        int type, s;
        ll x;
        cin >> type >> s;
        if (type == 1)
        {
            cin >> x;
            modify(io[s].F, -val[s] + x);
            modify(io[s].S + 1, val[s] - x);
            val[s] = x;
        }
        else
            cout << query(io[s].F) << '\n';
    }
}

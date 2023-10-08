/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
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

const ll mod = MOD2;

ll inv(ll b)
{
    ll a = 1, p = mod - 2;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll n, m, dp[1 << 20], i2 = inv(2);
vector<pii> E[20];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, t;
        cin >> t >> u >> v;
        u--, v--, t++;
        E[u].emplace_back(pii(v, t));
        E[v].emplace_back(pii(u, t));
    }

    dp[0] = 1;
    for (int mask = 0; mask + 1 < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
            if(!(mask >> i & 1))
            {
                ll c = 0;
                for (auto [j, t] : E[i])
                    if(!(mask >> j & 1))
                        c |= t;
                c = (c == 0 ? 1 : (c == 3 ? 0 : i2));
                dp[mask ^ (1 << i)] = (dp[mask ^ (1 << i)] + dp[mask] * c) % mod;
            }
    }

    ll fac = 1;
    for (int i = 1; i <= n; i++)
        fac = fac * i % mod;
    cout << dp[(1 << n) - 1] * inv(fac) % mod << '\n';
}

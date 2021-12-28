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

ll n, m, adj[25][25], dp[21][(1 << 21)];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1][v - 1]++;
    }
    dp[0][1] = 1;
    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            if (dp[i][mask])
                for (int j = 0; j < n; j++)
                    if ((mask & (1 << j)) == 0)
                        dp[j][mask ^ (1 << j)] = (dp[j][mask ^ (1 << j)] + dp[i][mask] * adj[i][j]) % MOD;
    cout << dp[n - 1][(1 << n) - 1] << '\n';
}

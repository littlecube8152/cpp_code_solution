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

ll n, m, k;
vector<vector<ll>> mtx(100, vector<ll>(100, 1.5e18));

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> c(100, vector<ll>(100, 1.5e18));

    for (int i = 0; i < 100; i++)
        for (int k = 0; k < 100; k++)
            for (int j = 0; j < 100; j++)
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
    return c;
}

vector<vector<ll>> fastpow(vector<vector<ll>> b, ll p)
{
    vector<vector<ll>> a(100, vector<ll>(100, 1.5e18));
    for (int i = 0; i < 100; i++)
        a[i][i] = 0;
    while (p)
    {
        if (p & 1)
            a = mul(a, b);
        p >>= 1;
        b = mul(b, b);
    }
    return a;
}

signed main()
{
    fast;

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        mtx[u - 1][v - 1] = min(mtx[u - 1][v - 1], w);
    }
    vector<vector<ll>> res = fastpow(mtx, k);
    cout << (res[0][n - 1] > 1e18 ? -1 : res[0][n - 1]) << '\n';
}
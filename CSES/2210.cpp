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

ll n, m, ans[1000005], p[1000005], tot;

ll fastpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % MOD;
        p >>= 1;
        b = b * b % MOD;
    }
    return a;
}

signed main()
{
    fast;

    cin >> n;
    cout << fastpow(4, MOD - 2) * ((fastpow(2, n * n % (MOD - 1)) + 2 * fastpow(2, ((n * n + 3) / 4) % (MOD - 1)) + fastpow(2, ((n * n + 1) / 2) % (MOD - 1))) % MOD) % MOD << '\n';
}
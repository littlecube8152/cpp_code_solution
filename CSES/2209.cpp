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

ll inv(ll b)
{
    ll p = MOD - 2, a = 1;
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

    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = (p[i - 1] * m) % MOD;
    for (int i = n; i >= 1; i--)
        if (n % i == 0)
        {
            ans[i] = p[n / i];
            for (int j = i * 2; j <= n; j += i)
                ans[i] = (ans[i] - ans[j] + MOD) % MOD;
        }

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            tot = (tot + ans[i] * inv(n / i)) % MOD;
    cout << tot << '\n';
}
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

ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll inv(ll b)
{
    return fpow(b, mod - 2);
}

ll dp[1000006], fac[1000006];

ll C(int n, int k)
{
    return fac[n] * inv(fac[k]) % mod * inv(fac[n - k]) % mod;
}

signed main()
{
    ll n;
    ll ans = 0;
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    if (n == 1)
    {
        cout << 3 << '\n';
        return 0;
    }
    // exact i columns
    for (int i = 1; i <= n; i++)
        ans = (ans + 2 * (fpow(3, i)) * C(n, i) % mod * fpow((fpow(3, n) - 3) % mod, n - i)) % mod;
    // one color: columns and rows
    // i rows are good, at least 1 column is good -> all (i rows are good) - i rows are good, every column is bad
    //
    for (int i = 1; i <= n; i++)
        dp[i] = (fpow(3, n * (n - i)) - fpow((fpow(3, n - i) - 1) % mod, n)) % mod;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum = (sum + dp[i] * (i % 2 == 1 ? 1 : -1) * C(n, i)) % mod;
    ans = (ans - sum * 3) % mod;
    cout << (ans + mod) % mod << '\n';
}
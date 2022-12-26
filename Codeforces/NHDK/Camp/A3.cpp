/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = MOD;

ll p, n, m, k, dp[2][2];

ll fastpow(ll b, ll p)
{
    ll a = 1;
    while (p > 0)
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
    return fastpow(b, mod - 2);
}

signed main()
{
    fast;
    char c;

    cin >> p >> n;
    for (int i = 1; i <= n; i++)
        cin >> c;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> c;
    cin >> k;
    ll q = (26 - n - m) * inv(26) % mod;
    ll prob = (((m * inv(26) % mod) * (1 - fastpow(q, p)) % mod) * inv((1 - q + mod) % mod)) % mod;
    cout << (1 - 2 * prob + 2 * mod) % mod << '\n';
}

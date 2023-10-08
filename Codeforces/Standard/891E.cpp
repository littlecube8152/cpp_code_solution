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

const ll mod = MOD;

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

ll C(ll n, ll k)
{
    ll a = 1;
    for (int i = 0; i < k; i++)
        a = a * (n - i) % mod;
    return a * inv(k) % mod;
}

ll n, k, a[5005], dp[2][5005][2], in;

signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    in = inv(n);

    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            for (int p = 0; p <= 1; p++)
            {
                // Case 1: a_i
                dp[(i + 1) & 1][j][p] = (dp[(i + 1) & 1][j][p] + dp[i & 1][j][p] * a[i + 1]) % mod;
                // Case 2: -1
                dp[(i + 1) & 1][j + 1][p] = (dp[(i + 1) & 1][j + 1][p] + dp[i & 1][j][p] * (mod - 1) % mod * in) % mod;
                // Case 3: 1
                if (!p)
                    dp[(i + 1) & 1][j][1] = (dp[(i + 1) & 1][j][1] + dp[i & 1][j][0] * in) % mod;
            }
        for (int j = 0; j <= n; j++)
            for (int p = 0; p <= 1; p++)
                dp[i & 1][j][p] = 0;
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++)
        ans += dp[n & 1][i][1] * C(k, i + 1) % mod;
    cout << ans % mod << '\n';
}

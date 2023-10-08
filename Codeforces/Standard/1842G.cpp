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

ll n, m, v, a[5005], dp[5005][5005], inv[5005];

signed main()
{
    fast;
    cin >> n >> m >> v;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
        {
            // Case 1: a_i
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * a[i + 1]) % mod;
            // Case 2: old X_i
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * v % mod * j) % mod;
            // Case 3: new X_i
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * v % mod * (m - j) % mod * (i + 1) % mod * inv[n]) % mod;
        }
    
    ll ans = 0;
    for (int i = 0; i <= n; i++)
        ans += dp[n][i];
    cout << ans % mod << '\n';
}

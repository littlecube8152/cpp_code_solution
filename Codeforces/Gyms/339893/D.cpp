/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

const ll mod = MOD;
ll n, dp[1000006], fac[1000006], invfac[1000006], onethreesix[1000006];

ll c(int n, int k)
{
    return (fac[n] * invfac[k] % mod) * invfac[n - k] % mod;
}

ll hulan(int i, int j)
{
    return (c(i + 1, i - j - 1) * fac[j] % mod) * onethreesix[j] % mod;
}

signed main()
{
    fast;
    cin >> n;

    fac[0] = invfac[0] = invfac[1] = 1;

    for (int i = 1; i <= n + 1; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 2; i <= n + 1; i++)
        invfac[i] = mod - (invfac[mod % i] * (mod / i) % mod);
    for (int i = 2; i <= n + 1; i++)
        invfac[i] = invfac[i - 1] * invfac[i] % mod;
    for (int i = 1; i <= n + 1; i++)
        onethreesix[i] = (onethreesix[i - 1] + i) % mod;
    
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j < n; j++)
    //         hulan[i][j] = c[i + 1][i - j - 1] * dp[j + 1] % mod;
    // 0
    // 0 1
    // 0 4 6
    // 0 10 30 36
    // 0 20 90 216 240
    // 0 35 210 756 1680 1800
    // 0 56 420 2016 6720 14400 15120
    // 0 84 756 4536 20160 64800 136080 141120
    // 0 120 1260 9072 50400 216000 680400 1411200 1451520
    // 0 165 1980 16632 110880 594000 2494800 7761600 15966720 16329600

    // 0 1 6 36 240 1800 15120
    // 0 1 2  6  24  120   840
    // 0 1 3  6  10   15

    ll ans = 0;
    for (int i = 1; i < n; i++)
        ans = (ans + hulan(n, i)) % mod;
    cout << ans << '\n';
}
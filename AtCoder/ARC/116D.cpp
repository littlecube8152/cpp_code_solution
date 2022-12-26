/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
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

const ll mod = 998244353;
ll N, M, dp[15][5005], pas[5005][5005];

ll C(int n, int k)
{
    if (n == k || 0 == k)
        return 1;
    if (!pas[n][k])
        pas[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % mod;
    return pas[n][k];
}

signed main()
{
    fast;
    cin >> N >> M;
    dp[0][0] = 1;
    for (int i = 0; i <= 13; i++)
        for (int j = 0; j <= M; j++)
            for (int k = 0; k <= min((M - j) / (1 << i), N); k += 2)
                dp[i + 1][j + k * (1 << i)] = (dp[i + 1][j + k * (1 << i)] + dp[i][j] * C(N, k)) % mod;
    cout << dp[14][M] << '\n';
}

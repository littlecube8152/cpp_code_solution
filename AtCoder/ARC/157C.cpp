/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = 998244353;
ll N, M, dp[2005][2005][3];
char c[2005][2005];

signed main()
{
    fast;
    cin >> N >> M;
    dp[1][1][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> c[i][j];
            ll up = (c[i][j] == 'Y' && c[i - 1][j] == 'Y'), left = (c[i][j] == 'Y' && c[i][j - 1] == 'Y');
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i][j][0]) % mod;
            dp[i][j][1] = (dp[i - 1][j][1] + up * dp[i - 1][j][0] + dp[i][j][1]) % mod;
            dp[i][j][2] = (dp[i - 1][j][2] + 2 * up * dp[i - 1][j][1] + up * dp[i - 1][j][0] + dp[i][j][2]) % mod;
            dp[i][j][0] = (dp[i][j - 1][0] + dp[i][j][0]) % mod;
            dp[i][j][1] = (dp[i][j - 1][1] + left * dp[i][j - 1][0] + dp[i][j][1]) % mod;
            dp[i][j][2] = (dp[i][j - 1][2] + 2 * left * dp[i][j - 1][1] + left * dp[i][j - 1][0] + dp[i][j][2]) % mod;
        }
    cout << dp[N][M][2] << '\n';
}

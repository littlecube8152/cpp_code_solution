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
// #pragma pack(0)
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

const ll mod = 1000000007;
int T, N, K, dp[105][105];

void solve()
{
    cin >> N >> K;
    for (int i = 0; i <= K; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for (int k = 0; k < N; k++)
        for (int i = 1; i <= K; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = (dp[i][j] + dp[i - 1][(j + N - k) % N]) % mod;
    for (int i = 1; i <= K; i++)
        for (int j = 0; j < N; j++)
            cout << dp[i][j] << " \n"[j == N - 1];
}

signed main()
{
    fast;
    cin >> T;
    while (T--)
        solve();
}

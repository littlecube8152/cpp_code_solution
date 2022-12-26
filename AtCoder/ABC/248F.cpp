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
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll N, P, dp[2][9000][2];

signed main()
{
    fast;
    cin >> N >> P;
    dp[1][1][1] = dp[1][0][0] = 1;
    for (int t = 2; t <= N; t++)
        for (int j = 0; j <= 3 * t - 2; j++)
        {
            int i = t & 1;
            dp[i][j][0] = dp[i][j][1] = 0;
            if (j >= 1)
                dp[i][j][0] = (dp[i][j][0] + dp[i ^ 1][j - 1][1] * 2) % P;
            if (j >= 2)
            {
                dp[i][j][1] = (dp[i][j][1] + dp[i ^ 1][j - 2][1] * 3) % P;
                dp[i][j][0] = (dp[i][j][0] + dp[i ^ 1][j - 2][0]) % P;
            }
            if(j >= 3)
                dp[i][j][1] = (dp[i][j][1] + dp[i ^ 1][j - 3][0] + dp[i ^ 1][j - 3][1]) % P;
        }
    for (int i = 1; i <= N - 1; i++)
        cout << dp[N & 1][3 * N - 2 - i][1] << " \n"[i == N - 1];
}

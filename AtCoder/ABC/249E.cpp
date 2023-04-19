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

ll N, dp[3005][3005], ans, P;

signed main()
{
    fast;
    cin >> N >> P;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            if (j >= 2)
                dp[i][j] = (dp[i][j] + ((dp[i - 1][j - 2] - (i < 10 ? 0 : dp[i - 10][j - 2]) + P) % P) * (j == 2 ? 26 : 25)) % P;
            if (j >= 3 && i >= 10)
                dp[i][j] = (dp[i][j] + ((dp[i - 10][j - 3] - (i < 100 ? 0 : dp[i - 100][j - 3]) + P) % P) * (j == 3 ? 26 : 25)) % P;
            if (j >= 4 && i >= 100)
                dp[i][j] = (dp[i][j] + ((dp[i - 100][j - 4] - (i < 1000 ? 0 : dp[i - 1000][j - 4]) + P) % P) * (j == 4 ? 26 : 25)) % P;
            if (j >= 5 && i >= 1000)
                dp[i][j] = (dp[i][j] + ((dp[i - 1000][j - 5] - (i < 10000 ? 0 : dp[i - 10000][j - 5]) + P) % P) * (j == 5 ? 26 : 25)) % P;
        }
        for (int j = 0; j <= N; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j]) % P;
    }
    // for (int i = 1; i <= N; i++)
    //     for (int j = 0; j <= N; j++)
    //         cout << (dp[i][j] - dp[i - 1][j]) << " \n"[j == N];
    for (int i = 1; i < N; i++)
        ans = (ans + dp[N][i] - dp[N - 1][i] + P) % P;
    cout << ans << '\n';
}

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

ll N, M, K, dp[2505], ans;

signed main()
{
    fast;
    cin >> N >> M >> K;
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = i * M; j >= 0; j--)
        {
            dp[j] = 0;
            for (int k = 1; k <= min((int)M, j); k++)
                dp[j] = (dp[j] + dp[j - k]) % MOD2;
        }
    for (int i = 1; i <= K; i++)
        ans = (ans + dp[i]) % MOD2;
    cout << ans << '\n';
}

/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, a, b;
double dp[105][605];

signed main()
{
    fast;

    cin >> n >> a >> b;
    double res = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6 * n; j++)
            for (int k = 1; k <= 6; k++)
                if (j >= k)
                    dp[i][j] += dp[i - 1][j - k];
    for (int i = a; i <= b; i++)
        res += dp[n][i];
    cout << fixed << setprecision(6) << res / powl(6.0, n) << '\n';
}
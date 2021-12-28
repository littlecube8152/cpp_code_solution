/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, dp[2][201][201], g[201][201], a[1001], p = 1;

signed main()
{
    fast;
    cin >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    a[0] = 1;

    while (cin >> a[p])
        ++p;
    p--;

    for (int i = 0; i <= 1; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++)
                dp[i][j][k] = 1e6;

    dp[0][2][3] = 0;

    for (int i = 0; i < p; i++)
    {
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++)
                dp[(i + 1) % 2][j][k] = 1e6;
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++)
            {
                dp[(i + 1) % 2][j][k] = min(dp[(i + 1) % 2][j][k], dp[i % 2][j][k] + g[a[i]][a[i + 1]]);
                dp[(i + 1) % 2][a[i]][k] = min(dp[(i + 1) % 2][a[i]][k], dp[i % 2][j][k] + g[j][a[i + 1]]);
                dp[(i + 1) % 2][j][a[i]] = min(dp[(i + 1) % 2][j][a[i]], dp[i % 2][j][k] + g[k][a[i + 1]]);
            }
    }

    int ans = 1e6;
    for (int j = 1; j <= m; j++)
        for (int k = 1; k <= m; k++)
            ans = min(ans, dp[p % 2][j][k]);
    cout << ans << '\n';
}

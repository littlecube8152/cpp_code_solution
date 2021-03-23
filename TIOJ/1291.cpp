#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, dp[201][201], ans, i, j;

signed main()
{
    fast;
    dp[0][0] = 1;
    for (i = 1; i <= 200; i++)
        for (j = 1; j <= 200; j++)
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % 1000000;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        ans = 0;
        for (j = 1; j <= n; j++)
            ans = (ans + dp[m][j]) % 1000000;
        cout << ans << '\n';
    }
}
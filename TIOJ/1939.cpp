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

ll n, dp[2][101];

signed main()
{
    dp[0][1] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= 100; i++)
    {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] * 2) % (MOD + 2);
        dp[1][i] = (dp[1][i - 1] * 3 + dp[0][i - 1]) % (MOD + 2);
    }
    cin >> n;
    while (cin >> n)
        cout << dp[1][n] << '\n';
}
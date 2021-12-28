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

int n, dp[1000005];

signed main()
{
    cin >> n;
    dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 1, dp[5] = 1, dp[6] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
            if (i - j > 0)
                dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
    cout << dp[n] << '\n';
}
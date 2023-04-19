#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1'000'000'007;
ll n, dp[200005][5];

signed main()
{
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 5; j++)
            dp[i][j] = (dp[i - 1][(j + 1) % 5] + dp[i - 1][(j + 4) % 5]) % mod;
    cout << dp[n][0] << '\n';
}

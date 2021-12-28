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

ll n, m, dp[100005][105], arr[100005], ans;

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    if (arr[1] == 0)
        for (int j = 1; j <= m; j++)
            dp[1][j] = 1;
    else
        dp[1][arr[1]] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (arr[i] == 0 || j == arr[i])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;

    for (int j = 1; j <= m; j++)
        ans = (ans + dp[n][j]) % MOD;
    
    cout << ans;
}
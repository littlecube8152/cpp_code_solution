//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, k, arr[101], dp[101][100001];

signed main()
{
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            dp[i][j] = ((dp[i - 1][j] - (j - arr[i] - 1 < 0 ? 0 : dp[i - 1][j - arr[i] - 1])) % MOD + MOD) % MOD;
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
    }
    cout << dp[n][k] << '\n';
}
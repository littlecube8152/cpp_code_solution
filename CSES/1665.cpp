#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, x, t[101], dp[2][101][10001], res;
signed main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    sort(t + 1, t + n + 1, [](int a, int b) { return a > b; });
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
            for (int k = 0; k <= 10000; k++)
            {
                dp[i % 2][j][k] = (dp[(i - 1) % 2][j][k] + j * dp[(i - 1) % 2][j][k]) % MOD;
                if (j > 0 && k >= t[i])
                    dp[i % 2][j][k] = (dp[i % 2][j][k] + dp[(i - 1) % 2][j - 1][k - t[i]]) % MOD;
                if (k + t[i] <= 10000)
                    dp[i % 2][j][k] = (dp[i % 2][j][k] + dp[(i - 1) % 2][j + 1][k + t[i]] * (j + 1)) % MOD;
            }
    }

    for (int k = 0; k <= x; k++)
        res = (res + dp[n % 2][0][k]) % MOD;
    cout << res << '\n';
}
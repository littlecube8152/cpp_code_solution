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

int n;
double p[3000], dp[3000][3000], ans;

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    dp[1][1] = p[1];
    dp[1][0] = 1.0 - p[1];
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (j == 0)
                dp[i][j] = dp[i - 1][j] * (1.0 - p[i]);
            else
                dp[i][j] = dp[i - 1][j] * (1.0 - p[i]) + dp[i - 1][j - 1] * p[i];
    for (int i = (n + 1) / 2; i <= n; i++)
        ans += dp[n][i];
    cout << fixed << setprecision(14) << ans << '\n';
}
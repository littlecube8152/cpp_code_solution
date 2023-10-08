#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n;
ll a[105], dp[105][105], d[105];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> d[1];
    for (int i = 2; i <= n + 1; i++)
        d[i] = d[i - 1] * 2 / 3;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            if (j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + min(a[i], d[j]));
            for (int k = 0; k <= i - 2; k++)
                dp[i][j] = max(dp[i][j], dp[k][j] + min(a[i], d[j]));
            for (int k = 0; k <= i - 3; k++)
                for (int l = 0; l <= n; l++)
                    dp[i][j] = max(dp[i][j], dp[k][l] + min(a[i], d[j]));
        }
    ll ans = 0;
    for (int j = 0; j <= n; j++)
        ans = max(ans, dp[n][j]);
    cout << ans << '\n';
}
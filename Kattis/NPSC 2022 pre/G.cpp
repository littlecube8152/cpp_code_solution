#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll n, m, a[1005], b[1005], dp[1005][1005], pa[1005], pb[1005];

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pa[i] = a[i] + pa[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        pb[i] = b[i] + pb[i - 1];
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 1e18;
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (pa[i] + pb[j] >= 0)
            {
                if (i)
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j], pa[i] + pb[j]));
                if (j)
                    dp[i][j] = min(dp[i][j], max(dp[i][j - 1], pa[i] + pb[j]));
            }
    cout << (dp[n][m] >= 1e17 ? -1 : dp[n][m]) << '\n';
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll dp[5005][5005], opt[5005][5005], a[5005];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        opt[i][i] = i;
        a[i] += a[i - 1];
    }
    for (int l = 1; l < n; l++)
        for (int i = 1; i + l <= n; i++)
        {
            int j = i + l;
            dp[i][j] = 1e18;
            for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++)
                if (dp[i][k] + dp[k + 1][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k + 1][j], opt[i][j] = k;
            dp[i][j] += a[j] - a[i - 1];
        }
    cout << dp[1][n] << '\n';
}

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, L, dp[405][405][205][2], dis[405][405], ans;
pll a[405];

signed main()
{
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
        cin >> a[i].F;
    for (int i = 1; i <= N; i++)
        cin >> a[i].S;
    for (int i = 1; i <= N; i++)
    {
        a[i + N] = a[i];
        a[i].F -= L;
    }
    N *= 2;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            dis[i][j] = dis[i][j - 1] + a[j].F - a[j - 1].F;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 0; k <= N / 2; k++)
                dp[i][j][k][0] = dp[i][j][k][1] = 2e17;

    for (int i = 1; i <= N; i++)
        dp[i][i][abs(a[i].S) >= abs(a[i].F)][0] = dp[i][i][abs(a[i].S) >= abs(a[i].F)][1] = abs(a[i].F);

    for (int len = 0; len < N / 2; len++)
        for (int i = 1; i <= N; i++)
        {
            int j = i + len;
            if (j <= N)
                for (int k = 0; k <= len + 1; k++)
                    if (dp[i][j][k][0] <= 1e17 || dp[i][j][k][1] <= 1e17)
                    {
                        // printf("%d %d %d %d = %lld\n", i, j, k, 0, dp[i][j][k][0]);
                        // printf("%d %d %d %d = %lld\n", i, j, k, 1, dp[i][j][k][1]);
                        ans = max(ans, (ll)k);
                        int dk = (dp[i][j][k][0] + dis[i - 1][i] <= a[i - 1].S);
                        dp[i - 1][j][k + dk][0] = min(dp[i - 1][j][k + dk][0], dp[i][j][k][0] + dis[i - 1][i]);

                        dk = (dp[i][j][k][0] + dis[i][j + 1] <= a[j + 1].S);
                        dp[i][j + 1][k + dk][1] = min(dp[i][j + 1][k + dk][1], dp[i][j][k][0] + dis[i][j + 1]);

                        dk = (dp[i][j][k][1] + dis[i - 1][j] <= a[i - 1].S);
                        dp[i - 1][j][k + dk][0] = min(dp[i - 1][j][k + dk][0], dp[i][j][k][1] + dis[i - 1][j]);

                        dk = (dp[i][j][k][1] + dis[j][j + 1] <= a[j + 1].S);
                        dp[i][j + 1][k + dk][1] = min(dp[i][j + 1][k + dk][1], dp[i][j][k][1] + dis[j][j + 1]);
                    }
        }
    cout << ans << '\n';
}
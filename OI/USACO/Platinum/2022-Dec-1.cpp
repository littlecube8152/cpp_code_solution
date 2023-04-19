#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, w[305][305], dp[305][305][9], ans[305 * 305];
pii e[305 * 305];

signed main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> w[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 0; k <= K; k++)
                dp[i][j][k] = (i == j && k == 0 ? 0 : 1e18);
    for (int i = 1; i <= N * N; i++)
        cin >> e[i].F >> e[i].S;
    for (int t = N * N; t >= 1; t--)
    {
        ans[t] = dp[1][N][K];
        auto [u, v] = e[t];
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                for (int k1 = 0; k1 < K; k1++)
                    for (int k2 = 0; k2 < K - k1; k2++)
                        dp[i][j][k1 + k2 + 1] = min(dp[i][j][k1 + k2 + 1], dp[i][u][k1] + w[u][v] + dp[v][j][k2]);
    }
    for (int i = 1; i <= N * N; i++)
        cout << (ans[i] > 1e16 ? -1 : ans[i]) << '\n';
}

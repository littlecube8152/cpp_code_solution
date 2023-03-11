#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, R, M, dp[3000][3000];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> R >> N >> M;
    R = N + 1 - R;
    if (N == 1)
        cout << 1 << '\n';
    else if (R == 1)
        cout << 0 << '\n';
    else
    {
        dp[1][1] = 1;
        for (int i = 1; i <= N - 1; i++)
            for (int j = 0; j <= i + 1; j++)
            {
                int k = i + (i < R ? 1 : -1) - 2 * j;
                dp[i + 1][j - (i == R - 1)] = (dp[i + 1][j - (i == R - 1)] + dp[i][j] * j) % M;
                dp[i + 1][j + 1 - (i == R - 1)] = (dp[i + 1][j + 1 - (i == R - 1)] + dp[i][j] * k) % M;
            }
        ll ans = 0;
        for (int i = 0; i <= N; i++)
            ans = (ans + dp[N][i]) % M;
        cout << ans << '\n';
    }
}

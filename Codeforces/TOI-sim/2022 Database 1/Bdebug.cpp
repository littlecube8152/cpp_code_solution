#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int mod = 31607;
int N;
double p[22][21], dp[22][(1 << 5)], val[22][(1 << 5)], ans, inv[mod];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    inv[1] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> p[i][j];
            p[i][j] = p[i][j] / 10000.0;
        }
    for (int i = 1; i <= N; i++)
    {
        for (int b = 0; b < (1 << N); b++)
        {
            int mask = b ^ ((b & (1 << (i - 1))) << (N - i + 2)) ^ ((b & (1 << (N - i))) << i);
            val[i][mask] = 1;
            for (int j = 0; j < N; j++)
                if ((b >> j) & 1)
                    val[i][mask] = val[i][mask] * p[i][j];
                else
                    val[i][mask] = val[i][mask] * (1.0 - p[i][j]);
            bitset<4> B = mask;
            cout << i << " " << B << " " << val[i][mask] << '\n';
        }
    }
    dp[0][(1 << (N + 2)) - 1] = 1;
    for (int i = 1; i <= N; i++)
    {
        // SoS DP: dp[i][mask] = dp[i - 1][mask] + dp[i - 1][mask ^ (1 << i)]
        for (int p = 0; p < N + 2; p++)
            for (int mask = 0; mask < (1 << (N + 2)); mask++)
                if ((mask & (1 << p)) == 0)
                    dp[i - 1][mask] = (dp[i - 1][mask] + dp[i - 1][mask ^ (1 << p)]);
                    
        ans = (ans + (1 - ans) * val[i][(1 << (N + 2)) - 1]);
        val[i][(1 << (N + 2)) - 1] = 0;

        for (int p = 0; p < N + 2; p++)
            for (int mask = 0; mask < (1 << (N + 2)); mask++)
                if ((mask & (1 << p)) == 0)
                    val[i][mask] = (val[i][mask] + val[i][mask ^ (1 << p)]);

        for (int mask = 0; mask < (1 << (N + 2)); mask++)
            dp[i][mask] = val[i][mask] * dp[i - 1][mask];

        for (int p = N + 1; p >= 0; p--)
            for (int mask = 0; mask < (1 << (N + 2)); mask++)
                if ((mask & (1 << p)) == 0)
                    dp[i][mask] = (dp[i][mask] - dp[i][mask ^ (1 << p)]);

        for (int mask = 0; mask < (1 << (N + 2)); mask++)
        {
            bitset<4> b = mask;
            cout << i << " " << b << " " << dp[i][mask] << '\n';
        }
        
        cout << ans << '\n';
    }
    for (int mask = 1; mask < (1 << (N + 2)) - 1; mask++)
        ans = (ans + dp[N][mask]);
    cout << ans << '\n';
}
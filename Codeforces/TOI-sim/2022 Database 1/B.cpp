#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int mod = 31607;
int N, p[22][21], dp[2][(1 << 23)], val[2][(1 << 23)], ans, inv[mod];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    inv[1] = 1;
    for (int i = 2; i < mod; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> p[i][j];
            p[i][j] = p[i][j] * inv[10000] % mod;
        }

    dp[0][(1 << (N + 2)) - 1] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int mask = 0; mask < (1 << (N + 2)); mask++)
            dp[i & 1][mask] = val[i & 1][mask] = 0;
        for (int b = 0; b < (1 << N); b++)
        {
            int mask = b ^ ((b & (1 << (i - 1))) << (N - i + 2)) ^ ((b & (1 << (N - i))) << i);
            val[i & 1][mask] = 1;
            for (int j = 0; j < N; j++)
                if ((b >> j) & 1)
                    val[i & 1][mask] = val[i & 1][mask] * p[i][j] % mod;
                else
                    val[i & 1][mask] = val[i & 1][mask] * (1 - p[i][j] + mod) % mod;
        }
        // SoS DP: dp[i][mask] = dp[i - 1][mask] + dp[i - 1][mask ^ (1 << i)]
        for (int p = 0; p < N + 2; p++)
            for (int mask = 0; mask < (1 << (N + 2)); mask++)
                if ((mask & (1 << p)) == 0)
                {
                    dp[(i ^ 1) & 1][mask] = dp[(i ^ 1) & 1][mask] + dp[(i ^ 1) & 1][mask ^ (1 << p)];
                    if (dp[(i ^ 1) & 1][mask] >= mod)
                        dp[(i ^ 1) & 1][mask] -= mod;
                }

        ans = (ans + ((1 - ans + mod) % mod) * val[i & 1][(1 << (N + 2)) - 1]) % mod;
        val[i & 1][(1 << (N + 2)) - 1] = 0;

        for (int p = 0; p < N + 2; p++)
            for (int mask = 0; mask < (1 << (N + 2)); mask++)
                if ((mask & (1 << p)) == 0)
                {
                    val[i & 1][mask] = val[i & 1][mask] + val[i & 1][mask ^ (1 << p)];
                    if (val[i & 1][mask] >= mod)
                        val[i & 1][mask] -= mod;
                }

        for (int mask = 0; mask < (1 << (N + 2)); mask++)
            dp[i & 1][mask] = val[i & 1][mask] * dp[(i ^ 1) & 1][mask] % mod;

        for (int p = N + 1; p >= 0; p--)
            for (int mask = 0; mask < (1 << (N + 2)); mask++)
                if ((mask & (1 << p)) == 0)
                {
                    dp[i & 1][mask] = dp[i & 1][mask] - dp[i & 1][mask ^ (1 << p)] + mod;
                    if (dp[i & 1][mask] >= mod)
                        dp[i & 1][mask] -= mod;
                }
    }
    for (int mask = 1; mask < (1 << (N + 2)) - 1; mask++)
    {
        ans = ans + dp[N & 1][mask];
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << '\n';
}
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K, M, dp[405][405], pre[405][405], slash[405][405];

int mad(int a, int b)
{
    if (a + b >= M)
        return a + b - M;
    return a + b;
}

int mub(int a, int b)
{
    if (a - b < 0)
        return a - b + M;
    return a - b;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // dp[i, j, k] how many combinations such that [1, i] is determined and A[i] + B[i] = j and k queries has been used
    // j -> j' (j' > j): k += j - j'
    // j -> j          : k unchanged
    // j -> j' (j' < j): whatever

    cin >> N >> K >> M;
    dp[0][0] = 1 % M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= K; k++)
                pre[j][k] = mad((j > 0 ? pre[j - 1][k] : 0), dp[j][k]);
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= K; k++)
                slash[j][k] = mad((j > 0 && k > 0 ? slash[j - 1][k - 1] : 0), dp[j][k]);

        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= K; k++)
            {
                dp[j][k] = (ll)(mub(mad(slash[j][k], pre[K][k]), pre[j][k])) * (j + 1) % M;
                // cout << dp[i][j][k] << " \n"[k == K];
            }
        // cout << '\n';
    }
    ll ans = 0;
    for (int j = 0; j <= K; j++)
        for (int k = 0; k <= K; k++)
            ans = (ans + dp[j][k]) % M;
    cout << ans << '\n';
}
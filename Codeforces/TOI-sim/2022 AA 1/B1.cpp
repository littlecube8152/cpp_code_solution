#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, L, K, v[255], dp[255][255][600];
const int mxC = 505;

void solve()
{
    cin >> N >> L >> K;
    assert(N == L);
    for (int i = 1; i <= N; i++)
    {
        int di, vi;
        cin >> di >> vi;
        v[di] = vi;
    }
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K + 1; j++)
            for (int k = 0; k <= mxC + 1; k++)
                dp[i][j][k] = ((j == K && 0 <= k && k <= mxC) ? 0 : -1e9);
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= K; j++)
            for (int k = 1; k <= mxC; k++)
                dp[i][j][k] = max({dp[i - 1][j + (k > v[i])][k - 1] + k,
                                   dp[i - 1][j + (k > v[i])][k] + k,
                                   dp[i - 1][j + (k > v[i])][k + 1] + k});
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= K; j++)
            cout << max(-1, dp[i][j][v[i]]) << " \n"[j == K];
    int ans = 0;
    for (int j = 0; j <= K; j++)
        for (int k = 1; k <= mxC; k++)
            ans = max(ans, dp[N][j][k]);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
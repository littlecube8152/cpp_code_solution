#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, pre[3][405], pos[3][405], dp[3][405][405][405];
char c[405];

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> c[i];
    for (int i = 1; i <= N; i++)
        pos[0][i] = pos[1][i] = pos[2][i] = N + 1;
    for (int i = 1; i <= N + 1; i++)
    {
        pre[0][i] = pre[0][i - 1] + (c[i] == 'R');
        pre[1][i] = pre[1][i - 1] + (c[i] == 'G');
        pre[2][i] = pre[2][i - 1] + (c[i] == 'Y');

        pos[0][pre[0][i]] = min(i, pos[0][pre[0][i]]);
        pos[1][pre[1][i]] = min(i, pos[1][pre[1][i]]);
        pos[2][pre[2][i]] = min(i, pos[2][pre[2][i]]);
    }
    for (int i = 0; i <= N; i++)
        for (int r = 0; r <= i; r++)
            for (int g = 0; g <= i - r; g++)
                for (int l = 0; l <= 2; l++)
                    dp[l][i][r][g] = 1e9;
    dp[0][0][0][0] = dp[1][0][0][0] = dp[2][0][0][0] = 0;
    for (int i = 1; i <= N; i++)
        for (int r = 0; r <= min(i, pre[0][N]); r++)
            for (int g = 0; g <= min(i - r, pre[1][N]); g++)
                for (int l = 0; l <= 2; l++)
                {
                    int y = i - r - g;
                    if (r > 0 && l != 0)
                        dp[0][i][r][g] = min(dp[0][i][r][g], dp[l][i - 1][r - 1][g] + abs(pre[1][pos[0][r]] - g) + abs(pre[2][pos[0][r]] - y));
                    if (g > 0 && l != 1)
                        dp[1][i][r][g] = min(dp[1][i][r][g], dp[l][i - 1][r][g - 1] + abs(pre[0][pos[1][g]] - r) + abs(pre[2][pos[1][g]] - y));
                    if (y > 0 && l != 2)
                        dp[2][i][r][g] = min(dp[2][i][r][g], dp[l][i - 1][r][g] + abs(pre[0][pos[2][y]] - r) + abs(pre[1][pos[2][y]] - g));
                }
    int ans = min({dp[0][N][pre[0][N]][pre[1][N]], dp[1][N][pre[0][N]][pre[1][N]], dp[2][N][pre[0][N]][pre[1][N]]});
    cout << (ans >= 1e9 ? -1 : ans / 2) << '\n';
}
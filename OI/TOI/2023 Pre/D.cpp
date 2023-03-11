#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int a, b, c, dp[31][31][31][61][2][2];
tuple<int, int, int, int, int, int> pre[31][31][31][61][2][2];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> c;
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            for (int k = 0; k <= c; k++)
                for (int l = 0; l <= max(2 * i, 2 * j); l++)
                    dp[i][j][k][l][0][0] = dp[i][j][k][l][0][1] = dp[i][j][k][l][1][0] = dp[i][j][k][l][1][1] = 1e9;
    dp[0][0][0][0][0][1] = 0;
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            for (int k = 0; k <= c; k++)
                for (int l = 0; l <= max(2 * i, 2 * j); l++)
                    for (int x = 0; x <= 1; x++)
                        for (int y = 0; y <= 1; y++)
                            for (int z = 0; z <= 1; z++)
                            {
                                int L = (y != z ? max(l, dp[i][j][k][l][x][y]) : l),
                                    val = (y != z ? 1 : dp[i][j][k][l][x][y] + 1),
                                    ii = i + (x == 0 && z == 0),
                                    jj = j + (x == 1 && z == 1),
                                    kk = k + (x + z == 1);
                                if (L >= 1e8)
                                    continue;

                                if (val < dp[ii][jj][kk][L][y][z])
                                    dp[ii][jj][kk][L][y][z] = val, pre[ii][jj][kk][L][y][z] = make_tuple(i, j, k, l, x, y);
                            }
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            for (int k = 0; k <= c; k++)
                for (int l = 0; l <= max(2 * i, 2 * j); l++)
                    if (dp[i][j][k][l][0][1] <= l)
                    {
                        printf("(%d, %d, %d) = %d (0", i, j, k, l);
                        auto [ii, jj, kk, ll, xx, yy] = make_tuple(i, j, k, l, 0, 1);
                        for (int t = 3; t <= i + j + k; t++)
                        {
                            tie(ii, jj, kk, ll, xx, yy) = pre[ii][jj][kk][ll][xx][yy];
                            printf("%d", xx);
                        }
                        printf("1)\n");
                        break;
                    }
    //
}

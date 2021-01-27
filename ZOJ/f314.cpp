#include <bits/stdc++.h>
using namespace std;
int m, n, a[55][10005] = {{0}}, dp[55][10005] = {{0}}, r = -500000000;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
            dp[i][j] = -500000000;
        }
    for (int i = 1; i <= m + 1; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (k == 1)
                    dp[i][j] = dp[i-1][k] + a[i][j] - a[i][k - 1];
                else if (k < j)
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j] - a[i][k - 1]);
                else if (k >= j)
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][k] - a[i][j - 1]);
    /*
    for (int i = 0; i <= m + 1; i++)
        for (int j = 1; j <= n; j++)
            cout << dp[i][j] << " \n"[j == n];
*/
    for (int j = 1; j <= n; j++)
        r = max(r, dp[m + 1][j]);
    cout << r << '\n';
}
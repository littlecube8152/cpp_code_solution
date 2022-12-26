#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

const int C = 17;
double dp[C + 2][C + 2][C + 2][C + 2][C + 1];

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    for (int i = 1; i <= C; i++)
        dp[i][0][0][0][0] = dp[0][i][0][0][0] = dp[0][0][i][0][0] = dp[0][0][0][i][0] = dp[0][0][0][0][i] = 1.0;
    for (int i = 0; i <= C; i++)
        for (int j = 0; j <= C; j++)
            for (int k = 0; k <= C; k++)
                for (int l = 0; l <= C; l++)
                    for (int m = 0; m <= C; m++)
                    {
                        double ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
                        for (int d = 0; d < i; d++)
                            ans1 = max(ans1, (1.0 - dp[d][j][k][l][m]) / ((i != 0) + (j != 0) + (k != 0) + (l != 0) + (m != 0)));
                        for (int d = 0; d < j; d++)
                            ans2 = max(ans2, (1.0 - dp[i][d][k][l][m]) / ((i != 0) + (j != 0) + (k != 0) + (l != 0) + (m != 0)));
                        for (int d = 0; d < k; d++)
                            ans3 = max(ans3, (1.0 - dp[i][j][d][l][m]) / ((i != 0) + (j != 0) + (k != 0) + (l != 0) + (m != 0)));
                        for (int d = 0; d < l; d++)
                            ans4 = max(ans4, (1.0 - dp[i][j][k][d][m]) / ((i != 0) + (j != 0) + (k != 0) + (l != 0) + (m != 0)));
                        for (int d = 0; d < m; d++)
                            ans5 = max(ans5, (1.0 - dp[i][j][k][l][d]) / ((i != 0) + (j != 0) + (k != 0) + (l != 0) + (m != 0)));
                        dp[i][j][k][l][m] = ans1 + ans2 + ans3 + ans4 + ans5;
                    }
    int i, j, k, l, m;
    for (int i = 0; i <= C; i++)
        for (int j = 0; j <= C; j++)
            for (int k = 0; k <= C; k++)
                for (int l = 0; l <= C; l++)
                    for (int m = 0; m <= C; m++)
                    {
                        int N = ((i != 0) + (j != 0) + (k != 0) + (l != 0) + (m != 0));
                        int one = ((i == 1) + (j == 1) + (k== 1) + (l == 1)+ (m == 1));
                        double ans = 0;
                        if (N == 1)
                            ans = 1;
                        else if (one == N)
                            ans = (one % 2 == 1 ? 1 : 0);
                        else if (one == N - 1)
                        {
                            if (N % 2 == 0)
                                ans = 0.5;
                            else 
                                ans = (N / 2 + 1) / (N * 1.0);
                        }
                        else
                           ans = 0.5;
                        if(abs(ans - dp[i][j][k][l][m]) > 1e-9)
                            cout << i << j << k << l << m << ":" << ans << ' ' << dp[i][j][k][l][m] << '\n';
                    }
}
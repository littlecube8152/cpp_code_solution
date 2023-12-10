#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

char c[160];
ll N, dp[160][160][160], a[160], cost[160][160], dp2[160];
/*
    dp[i][j][k]: maximum cost for range [i, j], there are aleady k characters form a palindrome of length k.
    calc from increasing order of i + j
*/
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int l = 1; l <= N; l++)
    {
        cin >> a[l];
        if (a[l] < 0)
            a[l] = -1e15;
    }
    for (int i = 1; i <= N; i++)
        cin >> c[i];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 0; k <= N; k++)
                dp[i][j][k] = -1e15;
    for (int i = 1; i <= N; i++)
        dp[i][i][1] = 0, dp[i][i - 1][0] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cost[i][j] = -1e15;

    for (int i = 1; i <= N; i++)
        dp[i][i][1] = 0;

    for (int l = 1; l <= N; l++)
        for (int i = 1; i + l - 1 <= N; i++)
        {
            int j = i + l - 1;

            for (int k = 2; k <= l; k++)
                if (c[i] == c[j])
                    dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j - 1][k - 2]);

            for (int k = 0; k <= l; k++)
                for (int m = 1; m <= l; m++)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i + m][j][k] + cost[i][i + m - 1]),
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - m][k] + cost[j - m + 1][j]);
                }

            for (int k = 0; k <= l; k++)
                cost[i][j] = max(cost[i][j], dp[i][j][k] + a[k]);
            dp[i][j][0] = cost[i][j];
        }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
            dp2[i] = max(dp2[i], dp2[j - 1] + max(0LL, cost[j][i]));
    }
    cout << *max_element(dp2 + 1, dp2 + 1 + N) << '\n';
}
#include "boxes.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[10000007][2], ans = 1e18;

ll delivery(int N, int K, int L, int p[])
{
    for (int i = 1; i <= N; i++)
        dp[i][0] = dp[max(0, i - K)][0] + p[i - 1] * 2;
    for (int i = N; i >= 1; i--)
        dp[i][1] = dp[min(N + 1, i + K)][1] + (L - p[i - 1]) * 2;
    for (int i = 0; i <= N; i++)
        ans = min(ans, dp[i][0] + dp[min(N + 1, i + K + 1)][1] + L);
    for (int i = 0; i <= N; i++)
        ans = min(ans, dp[i][0] + dp[i + 1][1]);
    return ans;
}

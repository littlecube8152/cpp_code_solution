#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[3005][3005], val[3005], n, k, sum;
bool caldp[3005][3005];
ll DP(int L, int R, int turn)
{
    if (!caldp[L][R])
    {
        caldp[L][R] = 1;
        if (L == R && turn == 1)
            dp[L][R] = val[L];
        else if (L == R && turn == -1)
            dp[L][R] = -val[L];

        else if (turn == 1)
            dp[L][R] = max(DP(L, R - 1, -1) + val[R], DP(L + 1, R, -1) + val[L]);
        else
            dp[L][R] = min(DP(L, R - 1, 1) - val[R], DP(L + 1, R, 1) - val[L]);
    }
    return dp[L][R];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n / k; i++)
        for (int j = 1; j <= k; j++)
        {
            ll x;
            cin >> x;
            val[i] += x;
            sum += x;
        }

    cout << (sum + DP(1, n / k, 1)) / 2 << " " << (sum - DP(1, n / k, 1)) / 2 << '\n';
}
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, L, K, d[505], v[505], dp[505][505];

void solve()
{
    cin >> N >> L >> K;
    for (int i = 1; i <= N; i++)
        cin >> d[i] >> v[i];
    d[0] = 0;
    d[N + 1] = L;
    for (int i = 0; i <= N + 1; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = -1e18;
    dp[0][K] = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        ll value[505] = {}, lost[505] = {};
        for (int j = max(0LL, i - N); j < i; j++)
        {
            if (abs(d[i] - d[j]) >= abs(v[i] - v[j]) || j == 0 || i == N + 1)
            {
                ll left = (d[j] + v[i] - v[j] + d[i]) / 2;
                if (j == 0)
                    left = 0;
                if (i == N + 1)
                    left = L;
                value[j] = (v[j] + 1 + v[j] + 1 + (left - d[j] - 1)) * (left - d[j]) / 2 + (v[i] + v[i] + (d[i] - left - 1)) * (d[i] - left) / 2;

                for (int k = j + 1; k < i; k++)
                    if (d[k] <= left)
                        lost[j] += (v[k] - v[j] < d[k] - d[j]);
                    else
                        lost[j] += (v[k] - v[i] < d[i] - d[k]);
                //cout << "value " << i << " " << j << " = " << value[j] << " (" << left << ") " << lost[j] << '\n';
            }
            else
                value[j] = -1;
        }
        for (int j = max(0LL, i - N); j < i; j++)
            if (value[j] >= 0)
                for (int k = 0; k <= K - lost[j]; k++)
                    dp[i][k] = max(dp[i][k], dp[j][k + lost[j]] + value[j]);
    }
    //for (int i = 0; i <= N + 1; i++)
    //    for (int k = 0; k <= K + 1; k++)
    //        cout << max(-1LL, dp[i][k]) << " \n"[k == K + 1];

    ll ans = 0;
    for (int j = 0; j <= K; j++)
        ans = max(ans, dp[N + 1][j]);
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}

/*
1
10 10 5
1 1
2 4
3 7
4 8
5 9
6 1
7 1
8 1
9 10
10 100

1
5 10 3
1 1
2 4
3 7
4 8
5 9
*/
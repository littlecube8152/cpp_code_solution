#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

ll N, M, Q, p, q, r, s, a[505], b[505], dp[505][505];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> Q;
    assert(Q == 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    while (Q--)
    {
        cin >> p >> q >> r >> s;
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= M; j++)
                dp[i][j] = 1e18;
        dp[p][q] = (a[p] + b[q] >= 0 ? a[p] + b[q] : (ll)1e18);
        for (int i = p; i <= r; i++)
            for (int j = q; j <= s; j++)
            {
                if (a[i + 1] + b[j] >= 0)
                    dp[i + 1][j] = min(dp[i + 1][j], max(dp[i][j], a[i + 1] + b[j]));
                if (a[i] + b[j + 1] >= 0)
                    dp[i][j + 1] = min(dp[i][j + 1], max(dp[i][j], a[i] + b[j + 1]));
            }
        cout << (dp[r][s] > 1e17 ? -1 : dp[r][s]) << '\n';
    }
}
#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, D, a[305], b[305], t[305];
ll dp[150005][2];

signed main()
{
    cin >> N >> M >> D;
    for (int i = 1; i <= M; i++)
        cin >> a[i] >> b[i] >> t[i];
    for (int i = 1; i <= M; i++)
    {
        int k = 1;
        ll d = D * (t[i] - t[i - 1]);
        deque<pll> mono;
        for (int j = 1; j <= N; j++)
        {
            for (; k <= min(N, d + j); k++)
            {
                while (!mono.empty() && mono.back().F <= dp[k][(i - 1) % 2])
                    mono.pop_back();
                mono.push_back(pll(dp[k][(i - 1) % 2], k + d));
            }
            while (mono.front().S < j)
                mono.pop_front();
            dp[j][i % 2] = mono.front().F + b[i] - abs(a[i] - j);
        }
    }
    ll ans = -1e18;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dp[i][M % 2]);
    cout << ans << '\n';
}
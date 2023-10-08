#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K;
ll dp[5005][5005], in[1000006], suf[1000006], tot;
char c[2000006];

ll f(pll p, ll x)
{
    return p.F * x + p.S;
}

ll check(pll p1, pll p2, pll p3)
{
    return (p1.S - p2.S) * (p3.F - p2.F) >= (p2.S - p3.S) * (p2.F - p1.F);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= 2 * N; i++)
        cin >> c[i];
    for (int i = 1, j = 0, k = 1; i <= N; i++, k++)
    {
        while (c[k] != 'B')
            j++, k++;
        in[i - 1] = j;
    }
    for (int i = 0; i < N; i++)
        in[i] = max((ll)i, in[i]);
    for (int i = 1, j = N, k = 1; i <= N; i++, k++)
    {
        while (c[k] != 'A')
            j--, k++;
        suf[i] = j;
    }
    for (int i = N; i >= 0; i--)
        suf[i] += suf[i + 1];

    for (int k = 0; k <= K; k++)
        for (int i = 0; i <= N; i++)
            dp[i][k] = 1e18;
    dp[0][0] = 0;
    for (int k = 1; k <= K; k++)
    {
        deque<pll> hull, free;
        auto update = [&](pll p)
        {
            while (hull.size() >= 2 && check(hull[(int)hull.size() - 2], hull.back(), p))
                hull.pop_back();
            hull.emplace_back(p);
        };
        free.emplace_back(pll(dp[k - 1][k - 1], k - 1));
        for (int i = k; i <= N; i++)
        {
            // dp[j][k - 1] + (i - in[j]) * (N - j) - (suf[in[j] + 1] - suf[i + 1])
            // dp[j][k - 1] + i * N - i * j - in[j] * N + in[j] * j - suf[in[j] + 1] + suf[i + 1]
            // dp[j][k - 1] - in[j] * N + in[j] * j - suf[in[j] + 1]
            //                                                       - i * j
            //                                                               + i * N + suf[i + 1]
            while (!free.empty() && in[free.front().S] < i)
            {
                int j = free.front().S;
                update(pll(-j, dp[j][k - 1] - in[j] * N + in[j] * j - suf[in[j] + 1]));
                free.pop_front();
            }
            while (hull.size() >= 2 && f(hull[0], i) > f(hull[1], i))
                hull.pop_front();

            if (!hull.empty())
                dp[i][k] = min(dp[i][k], f(hull[0], i) + i * N + suf[i + 1]);
            if (!free.empty())
                dp[i][k] = min(dp[i][k], free[0].F);
            free.emplace_back(pll(dp[i][k - 1], i));
            // cout << dp[i][k] << " \n"[i == N];
        }
    }
    cout << dp[N][K] << '\n';
}

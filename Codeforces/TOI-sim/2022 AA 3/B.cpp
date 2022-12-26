#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, C, K, pre[505], s[505][205], sz[505], cnt[505], off[505];
vector<ll> dp[505];
vector<pll> E[505];

void dfs(int u)
{
    sz[u] = 1;
    for (auto [v, w] : E[u])
        if (pre[u] != v)
        {
            pre[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
    off[u] = K;
    dp[u].resize(2 * K + 2);
    for (int i = -K; i <= K; i++)
        dp[u][off[u] + i] = 1e18;
    for (int i = 0; i <= C; i++)
        dp[u][off[u] + i - cnt[u]] = s[u][i];
    vector<ll> tmp = dp[u];
    sort(E[u].begin(), E[u].end(), [&](pii p1, pii p2)
         { return sz[p1.F] > sz[p2.F]; });
    for (auto [v, w] : E[u])
        if (pre[u] != v)
        {
            for (int i = -K; i <= K; i++)
                tmp[off[u] + i] = 1e18;
            for (int i = -K; i <= K; i++)
                for (int j = -K; j <= K; j++)
                    if (-K <= i + j && i + j <= K)
                        tmp[off[u] + i + j] = min(tmp[off[u] + i + j], dp[v][off[v] + i] + dp[u][off[u] + j] + abs(i * w));
            for (int i = -K; i <= K; i++)
                dp[u][off[u] + i] = tmp[off[u] + i];
        }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].emplace_back(pll{v, w});
        E[v].emplace_back(pll{u, w});
    }
    cin >> C;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= C; j++)
            cin >> s[i][j];
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    dfs(1);
    // for (int i = 1; i <= N; i++)
    //{
    //     cout << i << " ";
    //     for (int j = -sz[i] * C; j <= sz[i] * C; j++)
    //         cout << "[" << j << "] " << (double)dp[i][off[i] + j] << " ";
    //     cout << '\n';
    // }
    cout << dp[1][off[1] + 0] << '\n';
}
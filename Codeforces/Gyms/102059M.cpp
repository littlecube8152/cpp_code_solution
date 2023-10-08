#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll n, k, pre[250005];
pll dp[250005][2];
vector<pll> E[250005], T[250005];

void dfs(int u)
{
    dp[u][1] = pll(1, 0);
    for (auto [v, w] : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dfs(v);
            dp[u][0] = dp[u][0] + max(dp[v][0], dp[v][1]);
            dp[u][1] = dp[u][1] + dp[v][0];
            T[u].emplace_back(pll(v, w));
        }
}

pll operator+(pll p1, pll p2)
{
    return pll(p1.F + p2.F, p1.S + p2.S);
}
pll operator-(pll p1, pll p2)
{
    return pll(p1.F - p2.F, p1.S - p2.S);
}

ll calc(int u, ll p)
{
    dp[u][0] = dp[u][1] = pll(0, 0);
    for (auto [v, w] : T[u])
    {
        calc(v, p);
        dp[u][0] = dp[u][0] + max(dp[v][0], dp[v][1]);
    }
    for (auto [v, w] : T[u])
        dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + pll(w - p, 1));
    return max(dp[u][0], dp[u][1]).S;
}

ll aliens()
{
    ll l = -3e11, r = 2e6;
    while (l < r)
    {
        ll mid = (l + r < 0 ? (l + r) / 2 : (l + r + 1) / 2);
        if (calc(1, mid) < k)
            r = mid - 1;
        else
            l = mid;
    }
    calc(1, l);
    return max(dp[1][0].F + l * k, dp[1][1].F + l * k);
}

signed main()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].emplace_back(pll(v, w));
        E[v].emplace_back(pll(u, w));
    }
    dfs(1); // check max matching >= k
    if (max(dp[1][0].F, dp[1][1].F) + k > n)
        cout << "Impossible\n";
    else
        cout << aliens() << '\n';
}
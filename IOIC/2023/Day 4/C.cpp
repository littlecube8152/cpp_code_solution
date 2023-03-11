#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int n, pre[500005], ans = 500000;
vector<int> E[500005];

struct DP
{
    int a = 0, b = 0, c = 0;
} dp[500005], suf[500005];

DP merge(DP p, int k)
{
    if (k >= p.a)
        return DP{k, p.a, p.b};
    else if (k >= p.b)
        return DP{p.a, k, p.b};
    else if (k >= p.c)
        return DP{p.a, p.b, k};
    else
        return p;
}

void dfs(int u)
{
    for (auto v : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dfs(v);
            dp[u] = merge(dp[u], dp[v].a + 1);
            suf[u] = merge(suf[u], max(suf[v].a, dp[v].a + dp[v].b));
        }
}

void allroot(int u)
{
    // cout << u << ' ' << dp[u].a << ' ' << dp[u].b << ' ' << dp[u].c << '\n';
    for (auto v : E[u])
        if (v != pre[u])
        {
            int cur, nsuf;
            if (dp[u].a == dp[v].a + 1)
                cur = dp[u].b + dp[u].c;
            else if (dp[u].b == dp[v].a + 1)
                cur = dp[u].a + dp[u].c;
            else
                cur = dp[u].a + dp[u].b;

            if (suf[u].a == max(suf[v].a, dp[v].a + dp[v].b))
                nsuf = suf[u].b;
            else
                nsuf = suf[u].a;

            // cout << u << " -> " << v << ' ' << (max(cur, nsuf) + 1) / 2 << " + " << 1 << " + " << (max(dp[v].a + dp[v].b, suf[v].a) + 1) / 2 << '\n';
            ans = min(ans, max({max(cur, nsuf),
                                max(dp[v].a + dp[v].b, suf[v].a),
                                (max(cur, nsuf) + 1) / 2 + 1 + (max(dp[v].a + dp[v].b, suf[v].a) + 1) / 2}));

            suf[v] = merge(suf[v], max(nsuf, cur));

            if (dp[u].a == dp[v].a + 1)
                dp[v] = merge(dp[v], dp[u].b + 1);
            else
                dp[v] = merge(dp[v], dp[u].a + 1);

            allroot(v);
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    // for (int i = 1; i <= n; i++)
    //    cout << dp[i].a << ' ' << dp[i].b << ' ' << dp[i].c << '\n';
    allroot(1);

    cout << ans << '\n';
}
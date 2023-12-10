#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
int n, c[3005], cnt[3005], pre[3005], sz[3005];
ll ans;
vector<ll> ord, dp[3005], E[3005];

void dfs(int u)
{
    ord.emplace_back(u);
    for (auto v : E[u])
        if (v != pre[u])
            pre[v] = u, dfs(v);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i], cnt[c[i]]++;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    reverse(ord.begin(), ord.end());
    for (int i = 1; i <= n; i++)
        if (cnt[i])
        {
            for (int u : ord)
            {
                dp[u] = {0, 0, 0};
                sz[u] = 1;
                dp[u][(c[u] == i) ? 2 : 0] = 1;
                for (auto v : E[u])
                    if (v != pre[u])
                    {
                        int s = min(cnt[i], sz[u] + sz[v]), off = - sz[u] - sz[v] + s;
                        vector<ll> tmp(2 * s + 1, 0);
                        for (int x = 0; x <= 2 * sz[u]; x++)
                            for (int y = 0; y <= 2 * sz[v]; y++)
                                if (0 <= x + y + off && x + y + off <= 2 * s)
                                    tmp[x + y + off] = (tmp[x + y + off] + dp[u][x] * dp[v][y]) % mod;
                        sz[u] = s;
                        tmp.swap(dp[u]);
                    }
                dp[u][sz[u]]++;
                for (int j = sz[u] + 1; j <= 2 * sz[u]; j++)
                    ans = (ans + dp[u][j]) % mod;
            }
            // cerr << ans << '\n';
        }
    cout << ans << '\n';
}
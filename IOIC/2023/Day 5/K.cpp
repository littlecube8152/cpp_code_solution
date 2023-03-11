#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, K, dis[200005], dp[200005], vis[200005], ans = 1;
vector<int> E[200005];

int dfs(int u)
{
    vis[u] = 1;
    int res = dp[u];
    for (int v : E[u])
        if(!vis[v])
            res ^= dfs(v);
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M >> K;
    dp[1] = dp[N] = 1;
    for (int i = 1; i <= K; i++)
    {
        int u, v;
        cin >> u >> v;
        dp[u] ^= 1, dp[v] ^= 1;
    }
    for (int i = 1; i <= M - K; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++)
        if(!vis[i])
            if(dfs(i))
                ans = 0;
    cout << (ans ? "Yes" : "No") << '\n';
}
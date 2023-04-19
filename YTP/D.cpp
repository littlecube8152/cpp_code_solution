#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, M, c[100005], dp[100005], vis[100005];
bool valid = 1;
vector<pii> E[100005], tree[100005];
vector<int> ans;

void dfs(int u)
{
    for (auto [v, i] : E[u])
        if (!vis[v])
        {
            vis[v] = 1;
            tree[u].emplace_back(pii(v, i));
            dfs(v);
        }
}

void solve(int u)
{
    dp[u] ^= c[u];
    for (auto [v, i] : tree[u])
    {
        vis[v] = 2;
        solve(v);
        dp[u] ^= dp[v];
        if (dp[v])
            ans.emplace_back(i);
    }
}

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> c[i];
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(pii(v, i));
        E[v].emplace_back(pii(u, i));
    }
    for (int i = 1; i <= N; i++)
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
        }
    for (int i = 1; i <= N; i++)
        if (vis[i] < 2)
        {
            vis[i] = 2;
            solve(i);
            if (dp[i])
            {
                cout << "No\n";
                return 0;
            }
        }
    cout << "Yes\n"
         << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
}

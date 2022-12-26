#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, ans[200005], C[200005], pre[200005], dis[200005], mxdis[200005];
deque<int> E[200005], smalldp[200005], dp[200005];

void dfs(int u)
{
    for (int v : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dis[v] = dis[u] + 1;
            dfs(v);
            if (dp[v].size() >= dp[mxdis[u]].size())
                mxdis[u] = v;
        }
    smalldp[u].emplace_back(1);
    for (int v : E[u])
        if (v != pre[u] && v != mxdis[u])
        {
            smalldp[u].resize(max(smalldp[u].size(), dp[v].size() + 1));
            for (int i = 0; i < dp[v].size(); i++)
                smalldp[u][i + 1] += dp[v][i];
        }
        else if (v == mxdis[u])
        {
            ans[u] = ans[v];
            dp[v].swap(dp[u]);
            dp[u].push_front(0);
        }
    dp[u].resize(max(dp[u].size(), smalldp[u].size()));
    for (int i = 0; i < smalldp[u].size(); i++)
    {
        if (dp[u][i] == 0 && dp[u][i] + smalldp[u][i] == 1)
            ans[u]++;
        if (dp[u][i] == 1 && dp[u][i] + smalldp[u][i] > 1)
            ans[u]--;
        dp[u][i] += smalldp[u][i];
    }
}

void dfs2(int u)
{
    cout << u << ": [";
    for (int i : dp[u])
        cout << i << ", ";
    cout << "]\n";
    for (int v : E[u])
        if (v != pre[u] && v != mxdis[u])
        {
            for (int i = 0; i < dp[v].size(); i++)
            {
                if (dp[u][i + 1] == 1 && dp[u][i + 1] - dp[v][i] == 0)
                    ans[u]--;
                if (dp[u][i + 1] >= 2 && dp[u][i + 1] - dp[v][i] == 1)
                    ans[u]++;
                dp[u][i + 1] -= dp[v][i];
            }
            dp[v].resize(max(dp[u].size(), dp[v].size()));
            for (int i = 0; i < dp[u].size(); i++)
            {
                if (dp[v][i + 1] == 0 && dp[v][i + 1] + dp[u][i] == 1)
                    ans[u]++;
                if (dp[v][i + 1] == 1 && dp[v][i + 1] + dp[u][i] > 1)
                    ans[u]--;
                dp[v][i + 1] += dp[u][i];
            }
            dfs2(v);
            for (int i = 0; i < dp[u].size(); i++)
            {
                dp[v][i + 1] -= dp[u][i];
                if (dp[v][i + 1] == 0 && dp[v][i + 1] + dp[u][i] == 1)
                    ans[u]--;
                if (dp[v][i + 1] == 1 && dp[v][i + 1] + dp[u][i] > 1)
                    ans[u]++;
            }
            for (int i = 0; i < dp[v].size(); i++)
            {
                dp[u][i + 1] += dp[v][i];
                if (dp[u][i + 1] == 1 && dp[u][i + 1] - dp[v][i] == 0)
                    ans[u]++;
                if (dp[u][i + 1] >= 2 && dp[u][i + 1] - dp[v][i] == 1)
                    ans[u]--;
            }
        }
        else if (v == mxdis[u])
        {
            for (int i = 0; i < smalldp[u].size(); i++)
            {
                dp[u][i] -= smalldp[u][i];
                if (dp[u][i] == 0 && dp[u][i] + smalldp[u][i] == 1)
                    ans[u]--;
                if (dp[u][i] == 1 && dp[u][i] + smalldp[u][i] > 1)
                    ans[u]++;
            }
            dp[v].swap(dp[u]);
            dp[v].pop_front();
            dfs2(v);
            dp[v].swap(dp[u]);
            dp[u].push_front(0);
            for (int i = 0; i < smalldp[u].size(); i++)
            {
                if (dp[u][i] == 0 && dp[u][i] + smalldp[u][i] == 1)
                    ans[u]++;
                if (dp[u][i] == 1 && dp[u][i] + smalldp[u][i] > 1)
                    ans[u]--;
                dp[u][i] += smalldp[u][i];
            }
        }
}

signed main()
{
    cin >> N >> M;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= M; i++)
        cin >> C[i];
    dfs(1);
    dfs2(1);
    for (int i = 1; i <= N; i++)
        if (M == 1)
            cout << (ans[i] ? 1 : 0) << "\n";
        else
            cout << ans[i] << "\n";
}
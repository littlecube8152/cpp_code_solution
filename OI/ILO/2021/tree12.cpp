#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

ll N, h[2005], ans, vis[2005], dis[2005];
vector<int> E[2005], order;

void dfs(int k)
{
    vis[k] = 1;
    for (int i : E[k])
        if (!vis[i])
        {
            dis[i] = dis[k] - 1;
            dfs(i);
        }
    vis[k] = 0;
}

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> h[i];
    for (int i = 1; i <= N; i++)
        order.emplace_back(i);
    sort(order.begin(), order.end(), [&](int i, int j)
         { return h[i] < h[j]; });
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        dis[i] = N;
        dfs(i);
        ll light = 0;
        for (int j = 0; j < N; j++)
        {
            light += dis[order[j]];
            ans = max(ans, light - h[order[j]]);
        }
    }
    cout << ans << '\n';
}
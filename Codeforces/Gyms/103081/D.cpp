#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, R, dis[300005];
vector<pii> E[300005];
priority_queue<pii, vector<pii>, greater<>> pq;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M >> R >> R;
    for (int i = N; i < N + 2 * M; i += 2)
    {
        int u, v, w, j = i + 1;
        cin >> u >> v >> w;
        E[u].emplace_back(pii(i, 1));
        E[i].emplace_back(pii(u, 1));
        E[i].emplace_back(pii(j, 2 * w - 2));
        E[j].emplace_back(pii(i, 2 * w - 2));
        E[j].emplace_back(pii(v, 1));
        E[v].emplace_back(pii(j, 1));
    }
    for (int i = 0; i <= N + 2 * M; i++)
        dis[i] = 1e9;
    dis[0] = 0;
    pq.push(pii(0, 0));
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto [v, w] : E[u])
            if (d + w < dis[v])
            {
                dis[v] = d + w;
                pq.push(pii(dis[v], v));
            }
    }
    int ans = 0;
    for (int i = N; i < N + 2 * M; i += 2)
        if (dis[i] <= R || dis[i + 1] <= R)
            ans++;
    cout << ans << '\n';
}

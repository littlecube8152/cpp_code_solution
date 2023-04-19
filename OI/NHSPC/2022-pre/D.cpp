#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
// #define S second
using namespace std;

const ll mx = 150'000'000'000;
ll N, M, S, T, D, w[200005], p[200005], q[200005], dis[200005], pre[200005], ans[200005];
vector<pll> E[100005];

void dijk()
{
    priority_queue<pll, vector<pll>, greater<>> pq;
    for (int i = 1; i <= N; i++)
        dis[i] = 1e18;
    dis[S] = 0;
    pq.push(pll(0, S));
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto [v, i] : E[u])
            if (d + w[p[i]] < dis[v])
            {
                pre[v] = u;
                dis[v] = d + w[p[i]];
                pq.push(pll(dis[v], v));
            }
    }
}

signed main()
{
    cin >> N >> M >> S >> T >> D;
    for (int i = 1; i <= M; i++)
    {
        cin >> q[i];
        p[q[i]] = i;
    }
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(pll(v, i));
        E[v].emplace_back(pll(u, i));
    }
    int L = 1, R = M + 1;
    while (L < R)
    {
        int mid = (L + R) / 2;
        for (int i = 1; i <= M; i++)
            if (i <= mid)
                w[i] = i;
            else
                w[i] = mx + i;
        dijk();
        if (dis[T] <= D)
            R = mid;
        else
            L = mid + 1;
    }
    if (L == M + 1)
        cout << "NO\n";
    else
    {
        for (int i = 1; i <= M; i++)
            if (i <= L)
                w[i] = i;
            else
                w[i] = mx + i;
        dijk();
        w[L] += D - dis[T];
        cout << "YES\n";
        for (int i = 1; i <= M; i++)
            cout << w[p[i]] << " \n"[i == M];
    }
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, K;
ll T, dis[200005];
vector<pll> E[200005];
priority_queue<pll> pq;

signed main()
{
    cin >> N >> M >> T;
    for (int i = 1; i <= M; i++)
    {
        ll x, y, a, b, c;
        cin >> x >> y >> a >> b >> c;
        assert(b == 1);
        E[x].emplace_back(pll{y, c});
        E[y].emplace_back(pll{x, c});
    }
    dis[N] = T;
    for (int i = 1; i < N; i++)
        dis[i] = -1;
    pq.push(pll{dis[N], N});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] != d)
            continue;
        for (auto [v, w] : E[u])
            if (dis[u] - w > dis[v])
            {
                dis[v] = dis[u] - w;
                pq.push(pll{dis[v], v});
            }
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        int u;
        cin >> u;
        cout << dis[u] << '\n';
    }
}
/*
6 4 12
1 6 2 1 1
3 4 2 1 1
3 6 0 1 3
5 6 999999999 1 1000000000
5
1
2
3
4
5
*/
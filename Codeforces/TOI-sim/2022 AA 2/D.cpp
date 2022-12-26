#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, K;
ll T, dis[200005];
vector<tuple<int, ll, ll, ll>> E[200005];

ll bs(ll v, ll b, ll c, ll L, ll R, ll d)
{
    
}

signed main()
{
    cin >> N >> M >> T;
    for (int i = 1; i <= M; i++)
    {
        ll x, y, a, b, c;
        cin >> x >> y >> a >> b >> c;
        E[x].emplace_back(tie(y, a, b, c));
        E[y].emplace_back(tie(x, a, b, c));
    }
    priority_queue<pll> pq;
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
        for (auto [v, a, b, c] : E[u])
            if (dis[u] - c > dis[v])
            {
                dis[v] = dis[u] - c;
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
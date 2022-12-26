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

ll bs(int u, ll L, ll R)
{
    if (L == R)
        return L;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    ll mid = (L + R + 1) / 2;
    for (int i = 1; i <= N; i++)
        dis[i] = 2e18;
    dis[u] = mid;
    pq.push(pll{dis[u], u});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] != d)
            continue;
        for (auto [v, a, b, c] : E[u])
            if (dis[u] + min((a + dis[u]) % b, b - (a + dis[u]) % b) + c < dis[v])
            {
                dis[v] = dis[u] + min((a + dis[u]) % b, b - (a + dis[u]) % b) + c;
                pq.push(pll{dis[v], v});
            }
    }
    if (dis[N] <= T)
        return bs(u, mid, R);
    else
        return bs(u, L, mid - 1);
}

signed main()
{
    cin >> N >> M >> T;
    bool b1 = true;
    for (int i = 1; i <= M; i++)
    {
        ll x, y, a, b, c;
        cin >> x >> y >> a >> b >> c;
        b1 &= (b == 1);
        E[x].emplace_back(tie(y, a, b, c));
        E[y].emplace_back(tie(x, a, b, c));
    }
    if (b1)
    {
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
    else
    {
        cin >> K;
        assert(K == 1);
        for (int i = 1; i <= K; i++)
        {
            int u;
            cin >> u;
            cout << bs(u, -1, T) << '\n';
        }
    }
}
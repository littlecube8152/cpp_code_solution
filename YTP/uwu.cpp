#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define double long double
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd complex<double>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pii> E[5005], e;
ll N, M, Q, d[5005][5005];

void dijk(int r, ll *d)
{
    for (int i = 1; i <= N; i++)
        d[i] = 8e9;
    d[r] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, r));
    while(!pq.empty())
    {
        auto [dd, u] = pq.top();
        pq.pop();
        if(dd > d[u])
            continue;
        for (auto [v, w] : E[u])
            if(max(dd, w) < d[v])
            {
                d[v] = max(dd, w);
                pq.push(pii(d[v], v));
            }
    }
}

signed main()
{
    cout << std::numeric_limits<double>::digits10 << endl;
    fast;
    cin >> N >> M >> Q;
    for (int i = 1; i <= M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].emplace_back(v, w);
        E[v].emplace_back(u, w);
        e.emplace_back(u, v);
    }
    for (int i = 1; i <= N; i++)
        dijk(i, d[i]);
    for (int i = 1; i <= Q; i++)
    {
        ll ans = 2e9;
        int u, v;
        cin >> u >> v;
        for (auto [x, y] : e)
            ans = min(ans, max(d[u][x], d[v][y]));
        for (auto [x, y] : e)
            ans = min(ans, max(d[u][y], d[v][x]));
        if(ans >= 2e9)
            ans = -1;
        cout << ans << '\n';
    }
}
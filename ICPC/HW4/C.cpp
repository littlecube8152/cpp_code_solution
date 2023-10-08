#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, S, T, H[100005], dS[100005], dT[100005];
vector<int> E[100005];

struct LCT
{
    static const int C = 200'000;
    pll seg[800055];
    int vis[800055];
    vector<int> touch;
    void insert(pll p, int i = 1, int L = 0, int R = C)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            touch.emplace_back(i);
        }

        int mid = (L + R) / 2;
        if (p.F * mid + p.S < seg[i].F * mid + seg[i].S)
            swap(p, seg[i]);
        if (L == R)
            return;
        if (p.F > seg[i].F)
            insert(p, i << 1, L, mid);
        else
            insert(p, i << 1 | 1, mid + 1, R);
    }
    ll query(ll x, int i = 1, int L = 0, int R = C)
    {
        int mid = (L + R) / 2;
        if (L == R)
            return x * seg[i].F + seg[i].S;
        else if (x <= mid)
            return min(x * seg[i].F + seg[i].S, query(x, i << 1, L, mid));
        else
            return min(x * seg[i].F + seg[i].S, query(x, i << 1 | 1, mid + 1, R));
    }
    void init()
    {
        for (int i = 0; i <= 4 * (C + 1); i++)
            seg[i] = pll(0, 2e18);
    }
    void reset()
    {
        for (auto i : touch)
            vis[i] = 0, seg[i] = pll(0, 2e18);
        touch.clear();
    }
} lct;

void dijk(int r, ll *d)
{
    fill(d + 1, d + 1 + N, 2e18);
    d[r] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(pll(0, r));
    while (!pq.empty())
    {
        auto [D, u] = pq.top();
        pq.pop();
        if (d[u] != D)
            continue;
        for (auto v : E[u])
        {
            ll w = (H[u] - H[v]) * (H[u] - H[v]);
            if (D + w < d[v])
            {
                d[v] = D + w;
                pq.push(pll(d[v], v));
            }
        }
    }
}

signed main()
{
    cin >> N >> M >> S >> T;
    for (int i = 1; i <= N; i++)
    {
        cin >> H[i];
        H[i] *= 2;
    }
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dijk(S, dS);
    dijk(T, dT);
    ll ans = dS[T];
    lct.init();
    for (int i = 1; i <= N; i++)
    {
        // d(u, v) = dS[u] + dT[v] + 1/2(H[u] - H[v])^2
        //         = dS[u] + dT[v] + 1/2H[u]^2 + 1/2H[v]^2 - H[u] * H[v]
        lct.reset();
        for (auto j : E[i])
            lct.insert(pll(-H[j], dS[j] + H[j] * H[j] / 2));
        for (auto j : E[i])
            ans = min(ans, lct.query(H[j]) + dT[j] + H[j] * H[j] / 2);
    }
    for (int i : E[S])
        ans = min(ans, dT[i]);
    for (int i : E[T])
        ans = min(ans, dS[i]);
    cout << fixed << setprecision(1) << ans / 4.0 << '\n';
}
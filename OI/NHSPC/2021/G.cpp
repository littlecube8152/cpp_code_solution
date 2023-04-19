#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

ll n, s, t, w, pre[100005], echild[100005], bit[100005], T;
pii io[100005];
vector<pii> E[100005];

ll query(ll pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void modify(int pos, int val)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] += val;
}

void dfs(int k)
{
    io[k].F = ++T;
    for (pii p : E[k])
        if (p.F != pre[k])
        {
            pre[p.F] = k;
            echild[p.S] = p.F;
            dfs(p.F);
        }
    io[k].S = T;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s >> t >> w;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(pii{v, i});
        E[v].emplace_back(pii{u, i});
    }
    dfs(s);
    for (int i = 1; i <= n; i++)
        if (i != s)
        {
            modify(io[i].F, 1);
            modify(io[i].S + 1, -1);
        }
    for (int i = 1; i <= t + w; i++)
    {
        ll type, x, y, z;
        cin >> type;
        if (type == 1)
        {
            cin >> x >> y;
            cout << x * query(io[y].F) << '\n';
        }
        else
        {
            cin >> z;
            int u = echild[z];
            modify(io[u].F, -1);
            modify(io[u].S + 1, 1);
        }
    }
}
/*
5 1 3 2
1 2
2 3
2 4
5 2
1 5 5
2 2
1 2 3
2 4
1 5 5*/
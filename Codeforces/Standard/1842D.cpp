/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, m, t[105], k, x[105], in[105];
vector<pll> E[105];
vector<int> sol[105];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, y;
        cin >> u >> v >> y;
        E[u].emplace_back(pll(v, y));
        E[v].emplace_back(pll(u, y));
    }
    bool flag = 1;
    vector<int> cur = {1}, old;
    in[1] = 1;
    while (cur.back() != n)
    {
        ll nxt = 1e18;
        for (auto u : cur)
            for (auto [v, w] : E[u])
                if (!in[v])
                    nxt = min(nxt, w - x[u]);
        if (nxt >= 1e18)
        {
            cout << "inf\n";
            return 0;
        }
        sol[++k] = cur;
        t[k] = nxt;
        for (int i = 1; i <= n; i++)
            if (in[i])
                x[i] += nxt;

        for (auto u : cur)
            for (auto [v, w] : E[u])
                if (!in[v] && w == x[u])
                    old.emplace_back(v);
        for (auto u : old)
            cur.emplace_back(u);
        old.clear();
        sort(cur.begin(), cur.end());
        cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
        for (auto u : cur)
            in[u] = 1;
    }
    cout << x[1] << ' ' << k << '\n';
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
            in[j] = 0;
        for (auto j : sol[i])
            in[j] = 1;
        for (int j = 1; j <= n; j++)
            cout << in[j];
        cout << ' ' << t[i] << '\n';
    }
}

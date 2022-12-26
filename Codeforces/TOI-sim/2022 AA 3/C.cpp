#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, x[2000006];
ll ans[2000006];
vector<pll> E[1000006];

void dfs(int u)
{
    for (auto [v, w] : E[u])
    {
        ll a = abs(w);
        ans[v] = ans[u] - a * x[a] * x[a];
        if (w < 0)
            x[-w]--;
        else
            x[w]++;
        ans[v] += a * x[a] * x[a];
        dfs(v);
        if (w < 0)
            x[-w]++;
        else
            x[w]--;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        ll a;
        cin >> a;
        ans[0] -= a * x[a] * x[a];
        x[a]++;
        ans[0] += a * x[a] * x[a];
    }
    for (int i = 1; i <= K; i++)
    {
        int u, v = i, w;
        cin >> u >> w;
        E[u].emplace_back(pll{v, w});
    }
    dfs(0);
    ll out = 0;
    for (int i = 0; i <= K; i++)
        out ^= ans[i];
    cout << out << '\n';
}
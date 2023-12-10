#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

const int INF = 1e9;
int T, N, vis[1000006], dis[1000006];
vector<int> E[1000006];

void dfs(int u)
{
    vis[u] = 1;
    for (auto v : E[u])
        if (!vis[v])
        {
            dis[v] = dis[u] + 1;
            dfs(v);
        }
    vis[u] = 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
            E[i].clear();
        for (int i = 2; i <= N; i++)
        {
            int j;
            cin >> j;
            E[i].emplace_back(j);
            E[j].emplace_back(i);
        }

        dis[1] = 0;
        dfs(1);
        int u = max_element(dis + 1, dis + 1 + N) - dis;
        dis[u] = 1;
        dfs(u);
        int d = *max_element(dis + 1, dis + 1 + N);

        ll ans = 0;
        for (int i = 1; i <= d; i++)
            ans += (N - i + 1);

        cout << "Case #" << t << ": " << ans % 1'000'000'007 << '\n';
    }
}
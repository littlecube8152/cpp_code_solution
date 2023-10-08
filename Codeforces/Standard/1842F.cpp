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

int n, pre[5003], ans[5003], dis[5003];
vector<int> E[5003];

void dfs(int u)
{
    for (auto v : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dis[v] = dis[u] + 1;
            dfs(v);
        }
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i] = dis[i] = 0;
        dfs(i);
        sort(dis + 1, dis + 1 + n);
        for (int j = 0, s = 0; j <= n; j++)
            ans[j] = max(ans[j], (n - 1) * j - 2 * (s += dis[j]));
    }
    for (int i = 0; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, o[200005], t, vis[200005], order[200005];
vector<int> v, E[200005], revE[200005];
vector<vector<int>> scc;

void dfs(int k)
{
    for (int i : E[k])
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
        }
    o[k] = t++;
}

void dfs2(int k)
{
    for (int i : revE[k])
        if (vis[i])
        {
            vis[i] = 0;
            dfs2(i);
        }
    scc.back().emplace_back(k);
}
signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char c, d;
        int u, v;
        cin >> c >> u >> d >> v;
        E[m * (c == '+') + u].emplace_back(m * (d == '-') + v);
        E[m * (d == '+') + v].emplace_back(m * (c == '-') + u);
        revE[m * (d == '-') + v].emplace_back(m * (c == '+') + u);
        revE[m * (c == '-') + u].emplace_back(m * (d == '+') + v);
    }
    for (int i = 1; i <= 2 * m; i++)
    {
        v.emplace_back(i);
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
        }
    }
    sort(v.begin(), v.end(), [&](int a, int b)
         { return o[a] > o[b]; });
    for (int i : v)
        if (vis[i])
        {
            vis[i] = 0;
            scc.emplace_back(vector<int>{});
            dfs2(i);
        }

    for (int i = 1; i <= scc.size(); i++)
        for (int j : scc[i - 1])
            order[j] = i;

    for (int i = 1; i <= m; i++)
        if (order[i] == order[m + i])
        {
            //cout << order[i] << " " << order[i + m] << '\n';
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    for (int i = 1; i <= m; i++)
        if (order[i] < order[m + i])
            cout << '-' << " \n"[i == m];
        else
            cout << '+' << " \n"[i == m];
}

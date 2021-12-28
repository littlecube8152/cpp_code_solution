#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
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

ll n, m, q, dis[505][505];

signed main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dis[i][j] = 1000000000000;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        dis[x][y] = min(dis[x][y], w), dis[y][x] = min(dis[y][x], w);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1; i <= q; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (dis[x][y] >= 1000000000000)
            cout << "-1\n";
        else
            cout << dis[x][y] << '\n';
    }
}
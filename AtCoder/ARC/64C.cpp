/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll N, x[1005], y[1005], r[1005];
double dis[1005];
bool vis[1005];
signed main()
{
    fast;
    for (int i = 1; i <= 2; i++)
        cin >> x[i] >> y[i];
    cin >> N;
    N += 2;
    for (int i = 3; i <= N; i++)
        cin >> x[i] >> y[i] >> r[i];
    for (int i = 0; i <= N; i++)
        dis[i] = 1e18;
    dis[1] = 0;
    for (int t = 1; t <= N; t++)
    {
        int u = 0;
        for (int i = 1; i <= N; i++)
            if (dis[i] < dis[u] && !vis[i])
                u = i;
        vis[u] = 1;
        for (int v = 1; v <= N; v++)
            dis[v] = min(dis[v], dis[u] + max(0.0, sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v])) - r[u] - r[v]));
    }
    cout << fixed << setprecision(15) << dis[2] << '\n';
}

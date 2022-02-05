/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
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

int n, dis[100005], mind[100005], size[100005], dp[100005], a[100005];
vector<pii> e[100005];

void dfs(int k)
{

    size[k] = 1;
    for (pii p : e[k])
    {
        dis[p.F] = dis[k] + p.S;
        mind[p.F] = min(dis[p.F], mind[k]);
        dfs(p.F);
        size[k] += size[p.F];
        dp[k] += dp[p.F];
    }
    if (dis[k] - mind[k] > a[k])
        dp[k] = size[k];
    
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].pb((pii{i, y}));
    }
    dfs(1);

    cout << dp[1];
}

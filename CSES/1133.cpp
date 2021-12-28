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

ll n, pre[200005], dp[200005], Size[200005];
vector<int> E[200005];


void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            Size[k] += Size[i];
            dp[k] += dp[i];
        }
    dp[k] += Size[k] - 1;
}

void dfs2(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            dp[i] = dp[k] - Size[i] + (n - Size[i]);
            dfs2(i);
        }
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        Size[i] = 1;
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    //for (int i = 1; i <= n; i++)
        //cout << i << " | " << dp[i][0].F << " " << dp[i][1].F << '\n';
    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " \n"[i == n];
}

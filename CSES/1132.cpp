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

int n, pre[200005];
pii dp[200005][2];
vector<int> E[200005];

pii operator+(pii p, int i)
{
    return pii{p.F + i, p.S};
}

void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            if (dp[i][0].F + 1 >= dp[k][0].F)
            {
                dp[k][1] = dp[k][0];
                dp[k][0] = pii{dp[i][0].F + 1, i};
            }
            else if (dp[i][0].F + 1 >= dp[k][1].F)
                dp[k][1] = pii{dp[i][0].F + 1, i};
        }
}

void dfs2(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            if (dp[k][0].S != i)
            {
                if (dp[k][0].F + 1 >= dp[i][0].F)
                {
                    dp[i][1] = dp[i][0];
                    dp[i][0] = pii{dp[k][0].F + 1, k};
                }
                else if (dp[k][0].F + 1 >= dp[i][1].F)
                    dp[i][1] = pii{dp[k][0].F + 1, k};
            }
            else
            {
                if (dp[k][1].F + 1 >= dp[i][0].F)
                {
                    dp[i][1] = dp[i][0];
                    dp[i][0] = pii{dp[k][1].F + 1, k};
                }
                else if (dp[k][1].F + 1 >= dp[i][1].F)
                    dp[i][1] = pii{dp[k][1].F + 1, k};
            }
            dfs2(i);
        }
}

signed main()
{
    fast;
    cin >> n;
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
        cout << dp[i][0].F << " \n"[i == n];
}

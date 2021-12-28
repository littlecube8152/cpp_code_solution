#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x);
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, x, y, ans, pre[200005], dis[200005];
pii dp[2][2000005];
vector<int> e[200005];

void dfs(int k)
{
    for (int i : e[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dis[i] = dis[k] + 1;
            if(dis[i] > dp[0][k].F)
                dp[0][k] = pii{dis[i], i};
            else if(dis[i] > dp[1][k].F)
                dp[1][k] = pii{dis[i], i};
            dfs(i);
        }
}



signed main()
{
    fast;
}

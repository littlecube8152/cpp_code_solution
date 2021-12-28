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

ll n, pre[200005], ans[200005], color[200005], Size[200005];
set<int> val[200005];
vector<int> E[200005];

void dfs(int k)
{
    Size[k] = 1;
    int large = 0;
    for (int i : E[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dfs(i);
            Size[k] += Size[i];
            if (Size[i] >= Size[large])
                large = i;
        }
    if (large != 0)
        val[k].swap(val[large]);
    val[k].insert(color[k]);
    for (int i : E[k])
        if (pre[k] != i && large != i)
            for(int j : val[i])
                val[k].insert(j);
    ans[k] = val[k].size();
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

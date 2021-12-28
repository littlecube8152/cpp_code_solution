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

ll n, m, Eptr[200005], deg[200005];
vector<int> E[200005];
vector<int> ans;

void dfs(int k)
{
    for (; Eptr[k] < E[k].size();)
    {
        Eptr[k]++;
        dfs(E[k][Eptr[k] - 1]);
    }
    ans.emplace_back(k);
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        deg[u]--;
        deg[v]++;
    }
    deg[1]++;
    deg[n]--;
    for (int i = 1; i <= n; i++)
        if (deg[i])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    dfs(1);
    if (ans.size() <= m)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

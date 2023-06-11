/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
// #include <bits/extc++.h>
#include <bits/stdc++.h>
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int n, q, dp[1000006], pre[1000006], ans;
vector<int> E[1000006];

void dfs(int u)
{
    dp[u] = min(dp[u], u);
    for (int v : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dp[v] = dp[u];
            dfs(v);
        }
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    int t, z, x, last = 0;
    cin >> t >> z;
    ans = x = (z + last) % n + 1;
    dp[x] = x;
    dfs(x);
    for (int i = 2; i <= q; i++)
    {
        cin >> t >> z;
        x = (z + last) % n + 1;
        if (t == 1)
            ans = min(ans, dp[x]);
        else
            cout << (last = min(ans, dp[x])) << '\n';
    }
}

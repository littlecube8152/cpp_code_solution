/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, c[100005], pre[100005], dp[100005], ans;
vector<int> E[100005];

void dfs(int u)
{
    dp[u] = c[u];
    for (auto v : E[u])
        if (v != pre[u])
        {
            pre[v] = u;
            dfs(v);
            if (dp[u] != dp[v])
                dp[u] = 0;
        }
}

void calc(int u)
{
    bool flag = 1;
    map<int, int> mp;
    for (auto v : E[u])
    {
        mp[dp[v]]++;
        if (!dp[v])
            flag = 0;
    }
    mp[c[u]]++;
    if (flag)
        ans = u;
    for (auto v : E[u])
        if (v != pre[u])
        {
            mp[dp[v]]--;
            if (mp[dp[v]] == 0)
                mp.erase(dp[v]);
            int tmp = (mp.size() == 1 ? mp.begin()->F : 0);
            swap(dp[u], tmp);
            calc(v);
            swap(dp[u], tmp);
            mp[dp[v]]++;
        }
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1);
    calc(1);
    if (ans)
        cout << "YES\n"
             << ans << '\n';
    else
        cout << "NO\n";
}

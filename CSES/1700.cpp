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
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
const ll MOD = 1000000007;
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

unordered_map<unsigned int, unsigned int> mp;
ll t, n, pre[100005], dp[100005], sz[100005];
vector<int> E[100005];

void dfs(int k)
{
    unsigned int sum = 0;
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            sum += dp[i];
        }
    if (mp[sum] == 0)
        mp[sum] = rd();
    dp[k] = mp[sum];
}

void calcsz(int k)
{
    sz[k] = 1;
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            calcsz(i);
            sz[k] += sz[i];
        }
}

pair<unsigned int, unsigned int> hashing()
{
    for (int i = 1; i <= n; i++)
        pre[i] = 0, E[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    calcsz(1);
    vector<int> cent;
    for (int i = 1; i <= n; i++)
        if (n - sz[i] <= n / 2)
        {
            bool flag = 1;
            for (int j : E[i])
                if (j != pre[i] && sz[j] > n / 2)
                    flag = 0;
            if (flag)
                cent.emplace_back(i);
        }
    assert(cent.size() <= 2);
    cent.resize(2, cent.back());
    pair<unsigned int, unsigned int> res;
    pre[cent[0]] = 0;
    dfs(cent[0]);
    res.F = dp[cent[0]];
    pre[cent[1]] = 0;
    dfs(cent[1]);
    res.S = dp[cent[1]];

    return res;
}

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        mp.clear();
        cin >> n;
        auto [ada, dsa] = hashing();
        auto [nasa, dsdl] = hashing();
        if (ada == nasa || dsa == nasa)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

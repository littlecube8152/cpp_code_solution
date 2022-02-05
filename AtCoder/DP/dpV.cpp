/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

ll N, M, dp[100005], ans[100005], pre[100005];
vector<int> e[100005];
vector<int> lm[100005], rm[100005];

void dfs(int k)
{
    for (int i : e[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            dp[k] = dp[k] * (1 + dp[i]) % M;
        }
}

void dfs2(int k)
{
    for (int i : e[k])
        ans[k] = ans[k] * (1 + dp[i]) % M;

    lm[k] = vector<int>(e[k].size(), 1);
    rm[k] = vector<int>(e[k].size(), 1);

    for (int i = 1; i < e[k].size(); i++)
        lm[k][i] = lm[k][i - 1] * (1 + dp[e[k][i - 1]]) % M;
    for (int i = e[k].size() - 2; i >= 0; i--)
        rm[k][i] = rm[k][i + 1] * (1 + dp[e[k][i + 1]]) % M;



    for (int i = 0; i < e[k].size(); i++)
        if (e[k][i] != pre[k])
        {
            dp[k] = lm[k][i] * rm[k][i] % M;
            dfs2(e[k][i]);
        }
}

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].pb(y);
        e[y].pb(x);
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        ans[i] = 1;
    }
    dfs(1);
    dfs2(1);
    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}

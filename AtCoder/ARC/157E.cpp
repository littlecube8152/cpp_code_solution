/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = 998244353;
int T, N, A, B, C, P[10005], sz[10005];
vector<int> dp[10005][2], E[10005];

void dfs(int u)
{
    if (E[u].size() == 0)
    {
        sz[u] = 1;
        dp[u][0] = {0, 0};
        dp[u][1] = {0, 1};
    }
    else
    {
        int v = E[u][0], w = E[u][1];
        dfs(v);
        dfs(w);
        sz[u] = sz[v] + sz[w];
        dp[u][0] = dp[u][1] = vector<int>(sz[u] + 1, 0);
        for (int i = 0; i <= sz[v]; i++)
            for (int j = 0; j <= sz[w]; j++)
            {
                dp[u][0][i + j] = max({
                    dp[u][0][i + j],
                    dp[v][1][i] + dp[w][1][j],
                    dp[v][0][i] + dp[w][1][j],
                    dp[v][1][i] + dp[w][0][j],
                    dp[v][0][i] + dp[w][0][j],
                });
                dp[u][1][i + j] = max({
                    dp[u][1][i + j],
                    dp[v][0][i] + dp[w][0][j] + (u != 1),
                });
            }
        // cerr << u << ":\n";
        // for (int i = 0; i <= sz[u]; i++)
        //     cerr << dp[u][0][i] << " \n"[i == sz[u]];
        // for (int i = 0; i <= sz[u]; i++)
        //     cerr << dp[u][1][i] << " \n"[i == sz[u]];
    }
}

void solve()
{
    cin >> N >> A >> B >> C;
    for (int i = 1; i <= N; i++)
        E[i].clear();
    for (int i = 2; i <= N; i++)
    {
        cin >> P[i];
        E[P[i]].emplace_back(i);
    }
    if (C % 2 == 1)
    {
        cout << "No\n";
        return;
    }
    dfs(1);
    dp[1][0].resize(N), dp[1][1].resize(N);
    cout << (max((B - C / 2 >= 0 ? dp[1][0][B - C / 2] : -1), (B + 1 - C / 2 >= 0 ? dp[1][1][B + 1 - C / 2] : -1)) >= B ? "Yes\n" : "No\n");
}

signed main()
{
    fast;
    cin >> T;
    while (T--)
        solve();
}

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
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = 998'244'353;
int n, k, vis[105], sz[105];
ll dp[105][105][105], tmp[105][105], fac[105];
vector<int> E[105];

void merge(int u, int v)
{
    for (int i = 0; i <= sz[u] + sz[v]; i++)
        for (int j = 0; j <= sz[u] + sz[v]; j++)
            tmp[i][j] = 0;
    for (int i = 0; i <= sz[u]; i++)
        for (int j = 0; j <= sz[u]; j++)
            for (int x = 0; x <= sz[v]; x++)
                for (int y = 0; y <= sz[v]; y++)
                    tmp[i + x][j + y] = (tmp[i + x][j + y] + dp[u][i][j] * dp[v][x][y]) % mod;
    sz[u] += sz[v];
    for (int i = 0; i <= sz[u]; i++)
        for (int j = 0; j <= sz[u]; j++)
            dp[u][i][j] = tmp[i][j];
}

void dfs(int u)
{
    vis[u] = 1;
    sz[u] = 0;
    dp[u][0][0] = 1;
    for (auto v : E[u])
        if (!vis[v])
        {
            dfs(v);
            merge(u, v);
        }
    for (int i = 0; i <= sz[u] + 1; i++)
        for (int j = 0; j <= sz[u] + 1; j++)
            tmp[i][j] = 0;
    for (int i = 0; i <= sz[u]; i++)
        for (int j = 0; j <= sz[u]; j++)
        {
            tmp[i + 1][0] = (tmp[i + 1][0] + dp[u][i][j]) % mod;
            tmp[i][j + 1] = (tmp[i][j + 1] + dp[u][i][j]) % mod;
        }
    sz[u]++;
    for (int i = 0; i <= sz[u]; i++)
        for (int j = 0; j <= sz[u]; j++)
            dp[u][i][j] = tmp[i][j];
}

ll fpow(ll b, ll p = mod - 2)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        p >>= 1;
        b = b * b % mod;
    }
    return a;
}

signed main()
{
    cin >> n >> k;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        fill(vis + 1, vis + n + 1, 0);
        dfs(i);
        for (int j = 0; j < n; j++)
            for (int s = k + 1; s <= n; s++)
                ans = (ans + dp[i][j][s] * fac[j] % mod * fac[n - j - 1]) % mod;
    }
    cerr << ans << '\n';
    cout << (ans * fpow(fac[n]) % mod) << '\n';
}
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

const ll mod = MOD2;
ll k;
ll fac[100];

ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll inv(ll b)
{
    return fpow(b, mod - 2);
}

ll C(int n, int k)
{
    return fac[n] * inv(fac[k]) % mod * inv(fac[n - k]) % mod;
}

ll dp1[4005][80], dp2[4005][80], sz[4005], vis[4005];
ll wayn[200], waym[200];
vector<int> E[4005];
vector<int> cur;

void dfs(int u)
{
    vis[u] = sz[u] = 1;
    for (auto v : E[u])
        if (!vis[v])
        {
            dfs(v);
            sz[u] += sz[v];
        }
    vis[u] = 0;
    cur.emplace_back(u);
}

void cdec(int r, ll *way)
{
    cur.clear();
    dfs(r);
    int c = r;
    bool flag = 0;
    do
    {
        flag = 0;
        for (auto u : E[c])
            if (!vis[u] && sz[u] < sz[c] && sz[u] > sz[r] / 2)
            {
                c = u;
                flag = 1;
                break;
            }
    } while (flag);

    for (auto i : cur)
        for (int j = 0; j <= k; j++)
            dp1[i][j] = dp2[i][j] = 0;
    dp1[c][0] = dp2[c][0] = 1;

    for (int t = 0; t < k; t++)
        for (int i : cur)
            for (auto j : E[i])
                if (!vis[j])
                    dp2[j][t + 1] = (dp2[j][t + 1] + dp2[i][t]) % mod;
    vis[c] = 1;

    for (int t = 0; t < k; t++)
        for (int i : cur)
            for (auto j : E[i])
                if (!vis[j])
                    dp1[j][t + 1] = (dp1[j][t + 1] + dp1[i][t]) % mod;

    for (int i : cur)
    {
        for (int a = 0; a <= k; a++)
            for (int b = 0; b <= k; b++)
                way[a + b] = (way[a + b] + dp1[i][a] * dp2[i][b]) % mod;
            
    }

    for (auto u : E[c])
        if (!vis[u])
            cdec(u, way);
}

void calctree(int n, ll *way)
{
    for (int i = 1; i <= n; i++)
        E[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    cdec(1, way);
}

signed main()
{
    fast;
    int n, m;
    cin >> n >> m >> k;
    fac[0] = 1;
    for (int i = 1; i <= k; i++)
        fac[i] = fac[i - 1] * i % mod;
    if (k % 2 == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    calctree(n, wayn);
    calctree(m, waym);

    ll ans = 0;
    for (int i = 0; i <= k; i += 2)
        ans = (ans + wayn[i] * waym[k - i] % mod * C(k, i)) % mod;
    cout << ans << '\n';
}

/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#define int long long
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

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

const ll mod = 1'000'000'007;
int n, m, h, vis[200005];
ll ans = 1, p = -1;
pll f[200005];
vector<pii> E[200005];
int sol, type;

void check(ll x, ll y)
{
    if (x == -2)
        x = -x, y = -y;
    y = (y % h + h) % h;
    if (x == 0 && y != 0)
        type = 0;
    if (x == 2)
    {
        ll res;
        if (y % 2 == 0)
            res = y / 2;
        else if (h % 2 != 0)
            res = (y + h) / 2;
        else
            type = 0;

        if (type == 2)
            sol = res, type = 1;
        else if (type == 1 && sol != res)
            type = 0;
    }
}

void dfs(int u)
{
    for (auto [v, w] : E[u])
        if (!vis[v])
        {
            vis[v] = 1;
            f[v] = pii(-f[u].F, (w - f[u].S + h) % h);
            dfs(v);
        }
        else
            check(f[u].F + f[v].F, w - f[u].S - f[v].S);
}

void solve()
{
    cin >> n >> m >> h;
    ans = 1, p = -1;
    for (int i = 1; i <= n + m; i++)
    {
        vis[i] = 0;
        f[i] = pii(0, 0);
        E[i].clear();
    }
    for (int i = 1; i <= n; i++)
        for (int j = n + 1; j <= n + m; j++)
        {
            int k;
            cin >> k;
            if (k == -1)
                continue;
            E[i].emplace_back(pii(j, k));
            E[j].emplace_back(pii(i, k));
        }
    for (int i = 1; i <= n + m; i++)
        if (!vis[i])
        {
            f[i] = pii(1, 0);
            vis[i] = 1;
            type = 2;
            dfs(i);
            if (type == 0)
                ans = 0;
            if (type == 2)
                p++;
        }
    for (int i = 1; i <= p; i++)
        ans = ans * h % mod;
    cout << ans << '\n';
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}

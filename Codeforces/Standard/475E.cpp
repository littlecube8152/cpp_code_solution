/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
// #define int long long
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

int n, m, t, b, ans, vis[2005], pre[2005], sz[2005], in[2005], out[2005], bcc[2005], bsz[2005];
vector<int> E[2005], T[2005];

vector<int> tar;
void dfs(int u)
{
    vis[u] = 1;
    in[u] = ++t;
    out[u] = t;
    tar.emplace_back(u);
    for (auto v : E[u])
        if (!vis[v])
        {
            pre[v] = u;
            dfs(v);
            out[u] = min(out[u], out[v]);
        }
        else if (v != pre[u])
            out[u] = min(out[u], in[v]);

    if (out[u] == in[u])
    {
        bool flag = 1;
        ++b;
        while (flag)
        {
            int k = tar.back();
            if (k == u)
                flag = 0;
            bcc[k] = b;
            bsz[b]++;
            tar.pop_back();
        }
    }
}

pii dfsT(int u)
{
    int a = bsz[u], b = 0;
    for (auto v : T[u])
        if (v != pre[u])
        {
            pre[v] = u;
            auto [c, d] = dfsT(v);
            a += c;
            b += bsz[u] * c + d;
        }
    return pii(a, b);
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
        E[v].emplace_back(u);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        for (auto j : E[i])
            if (bcc[i] != bcc[j])
                T[bcc[i]].emplace_back(bcc[j]);

    for (int i = 1; i <= b; i++)
    {
        int k = n - bsz[i];
        for (int j = 1; j <= b; j++)
            pre[j] = 0;

        int common = bsz[i] * k;

        bitset<2000> dp;
        dp[0] = 1;

        for (auto j : T[i])
        {
            pre[j] = i;
            auto [a, b] = dfsT(j);
            dp |= dp << a;
            common += b;
        }
        for (int j = 0; j <= k; j++)
            if (dp[j])
                ans = max(ans, j * (k - j) + common);
    }
    for (int i = 1; i <= b; i++)
        ans += bsz[i] * bsz[i];
    cout << ans << '\n';
}

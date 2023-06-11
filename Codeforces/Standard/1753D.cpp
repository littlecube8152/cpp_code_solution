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

ll n, m, p, q, dis[300005];
string s[300005];
vector<pll> E[300005];
priority_queue<pll, vector<pll>, greater<>> pq;

int idx(ll i, ll j)
{
    return (i - 1) * m + j;
}

signed main()
{
    fast;
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dis[idx(i, j)] = (s[i][j] == '.' ? 0 : 1e18);
            if (s[i][j] == '.')
                pq.push(pll(0, idx(i, j)));
            if (s[i][j] == '#')
                continue;
            if (i >= 3 && s[i - 2][j] == 'U')
                E[idx(i, j)].emplace_back(pll(idx(i - 2, j), q));
            if (i + 2 <= n && s[i + 2][j] == 'D')
                E[idx(i, j)].emplace_back(pll(idx(i + 2, j), q));
            if (j >= 3 && s[i][j - 2] == 'L')
                E[idx(i, j)].emplace_back(pll(idx(i, j - 2), q));
            if (j + 2 <= m && s[i][j + 2] == 'R')
                E[idx(i, j)].emplace_back(pll(idx(i, j + 2), q));

            if (i >= 2 && j >= 2 && (s[i - 1][j - 1] == 'U' || s[i - 1][j - 1] == 'L'))
                E[idx(i, j)].emplace_back(pll(idx(i - 1, j - 1), p));
            if (i >= 2 && j < m && (s[i - 1][j + 1] == 'U' || s[i - 1][j + 1] == 'R'))
                E[idx(i, j)].emplace_back(pll(idx(i - 1, j + 1), p));
            if (i < n && j >= 2 && (s[i + 1][j - 1] == 'D' || s[i + 1][j - 1] == 'L'))
                E[idx(i, j)].emplace_back(pll(idx(i + 1, j - 1), p));
            if (i < n && j < m && (s[i + 1][j + 1] == 'D' || s[i + 1][j + 1] == 'R'))
                E[idx(i, j)].emplace_back(pll(idx(i + 1, j + 1), p));
        }

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] < d)
            continue;
        for (auto [v, w] : E[u])
            if (d + w < dis[v])
            {
                dis[v] = d + w;
                pq.push(pll(d + w, v));
            }
    }

    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < m; j++)
            ans = min(ans, dis[idx(i, j)] + dis[idx(i, j + 1)]);
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
            ans = min(ans, dis[idx(i + 1, j)] + dis[idx(i, j)]);
    cout << (ans >= 1e18 ? -1 : ans) << '\n';
}

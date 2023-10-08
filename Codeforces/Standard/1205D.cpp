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

int n, pre[1005], sz[1005], color[1005], dp[1005];
vector<int> E[1005];
vector<pair<pii, int>> sol;

void dfs(int u)
{
    sz[u] = 1;
    for (auto v : E[u])
        if(v != pre[u])
        {
            pre[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
}

void construct(int u, int r, int &nxt, int mul)
{
    dp[u] = (nxt += mul);
    sol.emplace_back(make_pair(pii(u, r), nxt - dp[r]));
    for (auto v : E[u])
        if(v != pre[u])
            construct(v, u, nxt, mul);
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
    int c = 1;
    dfs(c);
    while(1)
    {
        bool b = 1;
        for (auto v : E[c])
            if(v != pre[c] && sz[v] > n / 2)
            {
                c = v;
                b = 0;
                break;
            }
        if(b)
            break;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pre[c] = 0;
    dfs(c);
    pq.push(pii(0, 1));
    pq.push(pii(0, 2));
    pq.push(pii(0, 3));
    sort(E[c].begin(), E[c].end(), [&](int i, int j)
         { return sz[i] > sz[j]; });
    for (auto v : E[c])
    {
        auto [s, p] = pq.top();
        pq.pop();
        s += sz[v];
        color[v] = p;
        pq.push(pii(s, p));
    }
    pq.pop();
    pq.pop();
    int a = 0, b = 0, large = pq.top().S;
    for (auto v : E[c])
        if(color[v] != large)
            construct(v, c, a, 1);
    for (auto v : E[c])
        if(color[v] == large)
            construct(v, c, b, a + 1);
    for (auto [e, v] : sol)
        cout << e.F << ' ' << e.S << ' ' << v << '\n';
}

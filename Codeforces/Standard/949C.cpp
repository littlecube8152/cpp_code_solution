/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Since the day I applied ternary search on a non-convex function, everything was different.
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
// using namespace __gnu_pbds;

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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, m, h, u[100005], vis[100005], c[100005];
vector<int> sol, E[100005], order, R[100005];
vector<int> cc;

void dfs(int u)
{
    vis[u] = 1;
    for (int v : E[u])
        if (!vis[v])
            dfs(v);
    order.emplace_back(u);
}

void dfscc(int u, int id)
{
    c[u] = id;
    vis[u] = 1;
    for (int v : R[u])
        if (!vis[v])
            dfscc(v, id);
    cc.emplace_back(u);
}

signed main()
{
    fast;
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++)
        cin >> u[i];
    for (int i = 1; i <= n; i++)
        sol.emplace_back(i);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if ((u[a] + 1) % h == u[b])
        {
            // cerr << a << " -> " << b << '\n';
            E[a].emplace_back(b);
            R[b].emplace_back(a);
        }
        if ((u[b] + 1) % h == u[a])
        {
            // cerr << b << " -> " << a << '\n';
            E[b].emplace_back(a);
            R[a].emplace_back(b);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    reverse(order.begin(), order.end());
    for (int i : order)
    {
        if (!vis[i])
        {
            cc.clear();
            dfscc(i, i);
            int flag = 1;
            for (auto j : cc)
                for (int k : E[j])
                    if (c[k] == 0)
                        flag = 0;
            if (flag && cc.size() < sol.size())
                sol = cc;
        }
    }
    cout << sol.size() << '\n';
    for (int i : sol)
        cout << i << ' ';
    cout << '\n';
}

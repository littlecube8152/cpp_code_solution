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

int n, adj[4005][4005], vis[4005], is[4005];
vector<vector<int>> v;

void dfs(int k)
{
    v.back().emplace_back(k);
    for (int i = 1; i <= n; i++)
        if (!vis[i] && adj[i][k])
        {
            vis[i] = 1;
            dfs(i);
        }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        vis[i] = is[i] = 0;
    v.clear();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            adj[i][j] = c == '1';
        }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            v.emplace_back(vector<int>(0));
            vis[i] = 1;
            dfs(i);
        }
    int p = v.size(), q = 0;

    for (auto vv : v)
    {
        bool b = 1;
        for (auto i : vv)
        {
            bool c = 1;
            for (auto j : vv)
                if (!adj[i][j] && i != j)
                    b = c = 0;
            is[i] = c;
        }
        q += b;
    }
    if (p == 1)
    {
        cout << 0 << '\n';
        return;
    }
    for (auto vv : v)
        if (vv.size() == 1)
        {
            cout << 1 << '\n'
                 << vv[0] << '\n';
            return;
        }

    if (p > q)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (i != j)
                {
                    adj[i][j] = !adj[i][j];
                    adj[j][i] = !adj[j][i];
                }
            v = {vector<int>()};
            for (int j = 1; j <= n; j++)
                vis[j] = 0;
            vis[1] = 1;
            dfs(1);
            if (v[0].size() == n)
            {
                cout << 1 << ' ' << i << '\n';
                return;
            }
            for (int j = 1; j <= n; j++)
                if (i != j)
                {
                    adj[i][j] = !adj[i][j];
                    adj[j][i] = !adj[j][i];
                }
        }
    }
    else if (p == q && q == 2)
    {
        if (v[0].size() > v[1].size())
            swap(v[0], v[1]);
        cout << v[0].size() << '\n';
        for (int i : v[0])
            cout << i << ' ';
        cout << '\n';
    }
    else
    {
        cout << 2 << '\n';
        cout << v[0][0] << ' ' << v[1][0] << '\n';
    }
}

signed main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
        solve();
}

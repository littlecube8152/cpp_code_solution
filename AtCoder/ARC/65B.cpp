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

int n, k, l, vis[200005][2], ans[200005];
vector<int> E[200005], F[200005];
map<pii, int> mp;

void dfs(int u, int k)
{
    vis[u][0] = k;
    for(int v : E[u])
        if(!vis[v][0])
            dfs(v, k);
}

int dfs2(int u, int k)
{
    int tot = 1;
    vis[u][1] = k;
    for(int v : F[u])
        if(!vis[v][1])
            tot += dfs2(v, k);
    return tot;
}


signed main()
{
    cin >> n >> k >> l;
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= l; i++)
    {
        int u, v;
        cin >> u >> v;
        F[u].emplace_back(v);
        F[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
        if(!vis[i][0])
            dfs(i, i);
    for (int i = 1; i <= n; i++)
        if(!vis[i][1])
            /* ans[i] =*/ dfs2(i, i);
    for (int i = 1; i <= n; i++)
        mp[pii(vis[i][0], vis[i][1])]++;
    for (int i = 1; i <= n; i++)
        cout << mp[pii(vis[i][0], vis[i][1])] << " \n"[i == n];
}

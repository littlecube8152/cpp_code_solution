/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, nxt[200005], jump[200005], dis[200005], type[200005], cc[200005], cycdis[200005], cyclen[200005], cycpre[200005], t;
pii io[200005];
vector<int> revE[200005];

int dfs(int k, int c, int j)
{
    //cout << k << '\n';
    if (type[nxt[k]] == 2)
        return jump[k] = nxt[k];
    if (type[nxt[k]] == 1 && cc[nxt[k]] != c)
        return jump[k] = jump[nxt[k]];
    if (type[nxt[k]] == 1)
    {
        type[nxt[k]]++;
        if (j == 0)
        {
            dfs(nxt[k], c, nxt[k]);
            return nxt[k];
        }
        else
        {
            jump[k] = k;
            return dfs(nxt[k], c, j);
        }
    }
    type[nxt[k]]++;
    cc[nxt[k]] = c;
    jump[k] = dfs(nxt[k], c, j);
    return jump[k];
}

int order_cycle(int k, int r)
{
    //cout << "order cyc " << k << '\n';
    cc[k] = n + r;
    cycpre[nxt[k]] = k;
    if (nxt[k] == r)
    {
        cyclen[k] = cycdis[k] + 1;
        return k;
    }
    cycdis[nxt[k]] = cycdis[k] + 1;
    int last = order_cycle(nxt[k], r);
    cyclen[k] = cycdis[last] + 1;
    return last;
}

void order_tree(int k, int r)
{
    io[k].F = ++t;
    for (int i : revE[k])
        if (type[i] == 1)
        {
            dis[i] = dis[k] + 1;
            cc[i] = r;
            order_tree(i, r);
        }
    io[k].S = ++t;
}

int solve(int u, int v)
{
    if (type[u] == 1 && type[v] == 1)
    {
        if (io[v].F <= io[u].F && io[u].S <= io[v].S)
            return dis[u] - dis[v];
        else
            return -1;
    }
    if (type[u] == 2 && type[v] == 2)
    {
        if (cc[u] == cc[v])
            return (cycdis[v] - cycdis[u] + cyclen[v]) % cyclen[u];
        else
            return -1;
    }
    if (type[u] == 1 && type[v] == 2)
    {
        int j = jump[u];
        if (cc[j] == cc[v])
            return (cycdis[v] - cycdis[j] + cyclen[j]) % cyclen[v] + dis[u] - dis[j];
        else
            return -1;
    }
    return -1;
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> nxt[i];
        revE[nxt[i]].emplace_back(i);
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
        if (!type[i])
        {
            //cout << "  " << i << '\n';
            type[i]++;
            cc[i] = i;
            v.emplace_back(dfs(i, i, 0));
            jump[i] = v.back();
        }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for (int i : v)
    {
        if (!cycpre[i])
            order_cycle(i, i);
        order_tree(i, i);
    }
    /*
    cout << "cc ";
    for (int i = 1; i <= n; i++)
        cout << cc[i] << " \n"[i == n];
    cout << "jump ";
    for (int i = 1; i <= n; i++)
        cout << jump[i] << " \n"[i == n];
    cout << "type ";
    for (int i = 1; i <= n; i++)
        cout << type[i] << " \n"[i == n];
    cout << "cycdis ";
    for (int i = 1; i <= n; i++)
        cout << cycdis[i] << " \n"[i == n];
    cout << "cyclen ";
    for (int i = 1; i <= n; i++)
        cout << cyclen[i] << " \n"[i == n];
    cout << "dis ";
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " \n"[i == n];
    */
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }
}

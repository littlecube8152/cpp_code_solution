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

int n, q, nxt[200005], dis[200005][2], vis[200005];
vector<int> revE[200005];
void dfs(int k)
{
    if (vis[nxt[k]] < 2)
    {
        dis[nxt[k]][vis[nxt[k]]] = dis[k][vis[k] - 1] + 1;
        vis[nxt[k]]++;
        dfs(nxt[k]);
    }
    vis[k] |= 4;
}

void dfs2(int k)
{
    for (int i : revE[k])
        if (!vis[i])
        {
            dis[i][0] = dis[k][0] + 1;
            dfs2(i);
        }
}
signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nxt[i];
        revE[nxt[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            vis[i]++;
            dfs(i);
        }

    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 6)
        {
            dis[i][0] = dis[i][1] - dis[i][0];
            v.emplace_back(i);
        }
        vis[i] = 0;
    }

    for (int i : v)
        vis[i] = 1;
    for (int i : v)
        dfs2(i);
    for (int i = 1; i <= n; i++)
        cout << dis[i][0] << ' ';
}

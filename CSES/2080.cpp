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

ll N, K, pre[200005], Size[200005], vis[200005], dis[200005], discnt[200005];
vector<int> E[200005];
vector<ll> add;

void dfs_init(int k)
{
    vis[k] = 1;
    //cout << "init " << k << '\n';
    Size[k] = 1, pre[k] = 0, dis[k] = 0;
    for (int i : E[k])
        if (!vis[i])
        {
            dfs_init(i);
            Size[k] += Size[i];
        }
    vis[k] = 0;
}

int dfs_find(int k, int root)
{
    vis[k] = 1;
    bool valid = true;
    if (Size[root] - Size[k] > Size[root] / 2)
        valid = false;
    for (int i : E[k])
        if (!vis[i])
        {

            int ans = dfs_find(i, root);
            if (ans != 0)
            {
                vis[k] = 0;
                return ans;
            }
            if (Size[i] > Size[root] / 2)
                valid = false;
        }
    vis[k] = 0;
    if (valid)
        return k;
    else
        return 0;
}

void dfs_dis(int k)
{
    vis[k] = 1;
    if (add.size() <= dis[k])
        add.emplace_back(1);
    else
        add[dis[k]]++;
    for (int i : E[k])
        if (!vis[i])
        {
            dis[i] = dis[k] + 1;
            dfs_dis(i);
        }
    vis[k] = 0;
}

ll solve(int root)
{
    //cout << "solve " << root << '\n';
    dfs_init(root);
    int centroid = dfs_find(root, root);
    //cout << "centroid " << centroid << '\n';
    ll ans = 0;
    vis[centroid] = 1;
    for (int i = 0; i <= Size[root]; i++)
        discnt[i] = 0;
    discnt[0] = 1;
    for (int i : E[centroid])
        if (!vis[i])
        {
            add = vector<ll>{0};
            dis[i] = 1;
            dfs_dis(i);
            //cout << "subtree " << i << '\n';
            //for (int j = 0; j < add.size(); j++)
            //    cout << add[j] << " ";
            //cout << '\n';
            for (int j = 0; j < add.size(); j++)
                if (j <= K)
                    ans += add[j] * discnt[K - j];
            for (int j = 0; j < add.size(); j++)
                discnt[j] += add[j];

            //cout << "ans " << ans << '\n';
        }
    //cout << "ans " << ans << '\n';
    for (int i = 0; i <= Size[root]; i++)
        discnt[i] = 0;
    discnt[0] = 1;
    for (int i : E[centroid])
        if (!vis[i])
            ans += solve(i);
    return ans;
}

signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 2; i <= N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    cout << solve(1) << '\n';
}

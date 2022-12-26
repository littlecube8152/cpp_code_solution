/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

int N, sz[100005], dis[100005], pre[100005], deg[100005], npre[100005], validleaf[100005];
vector<int> E[100005];

void dfs_size(int k)
{
    sz[k] = 1;
    for (int i : E[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dfs_size(i);
            sz[k] += sz[i];
        }
}

bool dfs_dis(int k)
{
    if (deg[dis[k]] == -1)
        deg[dis[k]] = E[k].size();
    bool res = (deg[dis[k]] == (int)E[k].size());
    for (int i : E[k])
        if (npre[k] != i)
        {
            if(npre[k] == 0 || E[i].size() <= 2)
                validleaf[i] = validleaf[k];
            npre[i] = k;
            dis[i] = dis[k] + 1;
            res &= dfs_dis(i);
        }
    return res;
}

signed main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs_size(1);
    int cen = 0, ans = -1;
    for (int i = 1; i <= N; i++)
    {
        bool valid = (N - sz[i] <= N / 2);
        for (int j : E[i])
            if (pre[i] != j)
                valid &= (sz[j] <= N / 2);
        if (valid)
        {
            cerr << "[" << i << "]";
            for (int i = 0; i <= N; i++)
                deg[i] = -1, npre[i] = 0, dis[i] = 0;
            ans = (dfs_dis(i) ? i : ans);
            int minleaf = 0, mxleaf = 0;
            for (int i = 0; i <= N; i++)
                deg[i] = -1, npre[i] = 0, dis[i] = 0;
        }
    }
    cout << ans << '\n';
}
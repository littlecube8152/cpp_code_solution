/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma loop_opt(on)
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

pll operator+(pll p1, pll p2)
{
    return pll{p1.F + p2.F, p1.S + p2.S};
}
pll operator-(pll p1, pll p2)
{
    return pll{p1.F - p2.F, p1.S - p2.S};
}

pll tot[100005], subtot[17][100005];

vector<pll> E[100005];
int t[100005], head[17][100005], subhead[17][100005], sz[100005];
bool vis[100005], modified[100005];
ll dis[17][100005], ans[100005], last[100005], l1;

int S = 0;

int h, layer = 1;

int dfs(int k)
{
    vis[k] = 1;
    if (layer == 1)
        sz[k] = 1;
    int ans = 0;
    bool valid = 1;
    for (auto [i, w] : E[k])
        if (!vis[i])
        {
            ans = dfs(i);
            if (layer == 1)
                sz[k] += sz[i];
            valid &= (sz[i] <= S / 2);
            if (ans != 0)
                break;
        }
    vis[k] = 0;
    if (S - sz[k] <= S / 2 && valid)
        return k;
    return ans;
}

void dfs2(int k, int subh)
{
    sz[k] = vis[k] = 1;
    head[layer][k] = h;
    subhead[layer][k] = subh;
    for (auto [i, w] : E[k])
        if (!vis[i])
        {
            dis[layer][i] = dis[layer][k] + w;
            dfs2(i, (h == subh ? i : subh));
            sz[k] += sz[i];
        }
    vis[k] = 0;
}

int N, Q;

void centroid_dec(int i)
{
    int centroid = dfs(i);
    h = centroid;
    dfs2(centroid, centroid);
    vis[centroid] = 1;
    layer++;
    for (auto [j, w] : E[centroid])
        if (!vis[j])
        {
            S = sz[j];
            centroid_dec(j);
        }
    layer--;
}

signed main()
{
    fast;
    cin >> N >> Q;
    S = N;
    for (int i = 1; i < N; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;
        E[u].emplace_back(pll{v, w});
        E[v].emplace_back(pll{u, w});
    }
    centroid_dec(1);
    for (int i = 1; i <= Q; i++)
    {
        int t, x;

        cin >> t >> x;
        x++;
        if (t == 1)
        {
            if (!modified[x])
            {
                l1 = i;
                modified[x] = 1;
                for (int i = 1; i <= 16; i++)
                    if (head[i][x] != 0)
                    {
                        tot[head[i][x]] = tot[head[i][x]] + pll{1, dis[i][x]};
                        subtot[i][subhead[i][x]] = subtot[i][subhead[i][x]] + pll{1, dis[i][x]};
                    }
                    else
                        break;
            }
        }
        else if (t == 2)
        {
            if (last[x] <= l1)
            {
                last[x] = i;
                ans[x] = 0;
                for (int i = 1; i <= 16; i++)
                    if (head[i][x] != 0)
                    {
                        pll res = tot[head[i][x]];
                        if (head[i][x] != subhead[i][x])
                            res = res - subtot[i][subhead[i][x]];
                        ans[x] += res.F * dis[i][x] + res.S;
                    }
                    else
                        break;
            }
            cout << ans[x] << '\n';
        }
    }
}

/*
3 5
0 1 10000000000
1 2 10000000001
1 1
1 2
2 0
2 1
2 2
*/
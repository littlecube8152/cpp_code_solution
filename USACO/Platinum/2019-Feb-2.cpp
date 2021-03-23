#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, x, y, k, dis[1505][1505], vis[1505], ans;
vector<pii> e[1505];
unordered_map<int, pii> res;

void dfs1(int x, vector<int> &v)
{
    v.emplace_back(x);
    for (auto i : e[x])
        if (!vis[i.F])
            vis[x] = 1, dfs1(i.F, v);
    vis[x] = 0;
}

void dfs2(int x, int r, unordered_map<int, pii> &mp)
{
    for (auto i : e[x])
        if (!vis[i.F])
        {
            dis[r][i.F] = dis[r][x] + i.S;
            vis[i.F] = 1;
            mp[min(y, dis[r][i.F])].S = (mp[min(y, dis[r][i.F])].S + dis[r][i.F]) % MOD, mp[min(y, dis[r][i.F])].F = (mp[min(y, dis[r][i.F])].F + 1) % MOD;
            dfs2(i.F, r, mp);
        }
    vis[x] = 0;
}

signed main()
{
    fast;
    ifstream cin("mooriokart.in");
    ofstream cout("mooriokart.out");

    cin >> n >> m >> x >> y;
    k = n - m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e[x].emplace_back(pii{y, w});
        e[y].emplace_back(pii{x, w});
    }
    res[min(x * k, y)] = pii{1, x * k};
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            unordered_map<int, pii> mp, tmp;
            vector<int> v;
            vis[i] = 1;
            dfs1(i, v);
            for (int j : v)
                vis[j] = 1, dfs2(j, j, mp);
            for (int j : v)
                vis[j] = 1;
            for (auto &p : mp)
                p.S.F /= 2, p.S.S /= 2;
            for (auto p : mp)
                for (int q = 0; q <= y; q++)
                    tmp[min(y, p.F + q)] = make_pair((tmp[min(y, p.F + q)].F + res[q].F * p.S.F) % MOD, (tmp[min(y, p.F + q)].S + res[q].F * p.S.S + p.S.F * res[q].S) % MOD);
            res = tmp;
        }
    ans = res[y].S;
    for (int i = k - 1; i > 0; i--)
        ans = (ans * i) % MOD;
    for (int i = k - 1; i > 0; i--)
        ans = (ans * 2) % MOD;
    cout << ans << '\n';
}
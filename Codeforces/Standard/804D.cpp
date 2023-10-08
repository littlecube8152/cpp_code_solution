/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
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

int n, m, q, k, cc[100005], dia[100005], vis[100005], a[100005], b[100005];
ll sz[100005];
vector<int> E[100005], cur;
vector<ll> d[100005], occ[100005], sum[100005];
map<pair<int, int>, ll> mp;

void dfs(int u, int *dis)
{
    vis[u] = 1;
    cur.emplace_back(u);
    for (auto v : E[u])
        if (!vis[v])
        {
            dis[v] = dis[u] + 1;
            dfs(v, dis);
        }
}

signed main()
{
    fast;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    a[0] = b[0] - 1;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            ++k;
            // find u
            cur.clear();
            dfs(i, a);
            sz[k] = cur.size();
            int u = 0, v = 0;
            for (auto j : cur)
            {
                vis[j] = 0;
                cc[j] = k;
                if (a[j] > a[u])
                    u = j;
            }
            // find v
            a[u] = 0;
            cur.clear();
            dfs(u, a);
            for (auto j : cur)
            {
                vis[j] = 0;
                if (a[j] > a[v])
                    v = j;
            }
            dia[k] = a[v];
            // find all dis
            cur.clear();
            dfs(v, b);
            occ[k].resize(dia[k] + 1);
            d[k].resize(dia[k] + 1);
            sum[k].resize(dia[k] + 1);
            for (auto j : cur)
                occ[k][max(a[j], b[j])]++;
            d[k][0] = occ[k][0];
            for (int j = 1; j <= dia[k]; j++)
                d[k][j] = d[k][j - 1] + occ[k][j];
            for (int j = 1; j <= dia[k]; j++)
                sum[k][j] = sum[k][j - 1] + occ[k][j] * j;
        }

    cout << fixed << setprecision(10);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u = cc[u], v = cc[v];
        if (u == v)
        {
            cout << -1 << '\n';
            continue;
        }
        if (d[v].size() < d[u].size())
            swap(u, v);
        ll low = max(dia[u], dia[v]);
        if (!mp[pii(u, v)])
        {
            for (int i = 0; i < occ[u].size(); i++)
            {
                // i + j + 1 <= low does not count,
                // j <= low - i - 1
                int j = min((ll)occ[v].size() - 1, low - i - 1);
                mp[pii(u, v)] += occ[u][i] * ((i + 1) * (d[v].back() - (j < 0 ? 0 : d[v][j])) + (sum[v].back() - (j < 0 ? 0 : sum[v][j])));
                if (j >= 0)
                    mp[pii(u, v)] += occ[u][i] * low * d[v][j];
            }
        }
        cout << double(mp[pii(u, v)]) / sz[u] / sz[v] << '\n';
    }
}

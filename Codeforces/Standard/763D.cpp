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
#define ull unsigned ll
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

map<ull, ull> ha;
map<ull, int> mp;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

void insert(ull x)
{
    mp[x]++;
}

void erase(ull x)
{
    mp[x]--;
    if (mp[x] == 0)
        mp.erase(x);
}

ull gethash(ull k)
{
    while (!ha[k])
        ha[k] = rd();
    return ha[k];
}

int n, ans[100005], vis[100005], pre[100005], sz[100005];
ull h[100005][20];
vector<int> E[100005];
vector<ull> hs[100005][20];

void calcsz(int u)
{
    vis[u] = sz[u] = 1;
    for (auto v : E[u])
        if (!vis[v])
        {
            calcsz(v);
            sz[u] += sz[v];
        }
    vis[u] = 0;
}

void calch(int u, int p, int r, int l)
{
    vis[u] = 1;
    h[u][l] = 0;
    for (auto v : E[u])
        if (!vis[v])
            calch(v, u, r, l);
    for (auto v : E[u])
        if (v != p)
            h[u][l] += h[v][l];
    h[u][l] = gethash(h[u][l]);
    hs[r][l].emplace_back(h[u][l]);
    vis[u] = 0;
}

void cdec(int r, int l)
{
    calcsz(r);
    int c = r;
    {
        bool b = 1;
        while (b)
        {
            b = 0;
            for (auto v : E[c])
                if (sz[v] < sz[c] && sz[v] > sz[r] / 2)
                {
                    c = v, b = 1;
                    break;
                }
        }
    }
    vis[c] = 1;
    ull sum = 0;
    for (auto u : E[c])
        if (!vis[u])
        {
            calch(u, 0, u, l);
            for (auto v : hs[u][l])
                insert(v);
        }
    for (auto u : E[c])
        sum += h[u][l];
    
    insert(gethash(sum));

    // cerr << c;
    // for (auto [i, j] : mp)
    //     cerr << " (" << i << ", " << j << ") ";
    // cerr << '\n';

    ans[c] = mp.size();
    erase(gethash(sum));
    for (auto u : E[c])
        if (!vis[u])
        {
            for (auto v : hs[u][l])
                erase(v);
            sum -= h[u][l];
            insert(gethash(sum));
            for (int m = l + 1; m < 20; m++)
                h[c][m] = gethash(sum);
            cdec(u, l + 1);
            erase(gethash(sum));
            sum += h[u][l];
            for (auto v : hs[u][l])
                insert(v);
        }

    for (auto u : E[c])
        if (!vis[u])
            for (auto v : hs[u][l])
                erase(v);
    vis[c] = 0;
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    cdec(1, 0);
    // for (int i = 1; i <= n; i++)
    //     cerr << ans[i] << " \n"[i == n];
    cout << max_element(ans + 1, ans + 1 + n) - ans << '\n';
}

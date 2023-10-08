#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, t, a[500005], b[500005], pa[500005], pb[500005], sza[500005], szb[500005], ans[500005];
pii ta[500005], tb[500005];
vector<int> T1[500005], T2[500005];
vector<pii> in[500005], out[500005];

void rect(int l, int r, int d, int u)
{
    if (r < l)
        return;
    if(u < d)
        return;

    // cerr << "rect: " << l << ' ' << r << ' ' << d << ' ' << u << '\n';
    in[d].emplace_back(l, r);
    out[u + 1].emplace_back(l, r);
}

void calcsz(int u, int *p, int *sz, vector<int> *T)
{
    sz[u] = 1;
    for (auto v : T[u])
        if (v != p[u])
        {
            p[v] = u;
            calcsz(v, p, sz, T);
            sz[u] += sz[v];
        }
}

void doedge(int *sz, vector<int> *T)
{
    for (int i = 1; i <= n; i++)
    {
        sort(T[i].begin(), T[i].end(), [&](int a, int b)
             { return sz[a] < sz[b]; });
        if (i > 1)
            T[i].pop_back();
    }
}

void getorder(int u, int *s, pii *ts, vector<int> *T)
{
    s[++t] = u;
    ts[u].F = t;
    for (auto v : T[u])
        getorder(v, s, ts, T);
    ts[u].S = t;
}

int bit[500005];
void modify(int pos, int val)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] += val;
}

int query(int pos)
{
    int res = 0;
    for (int i = pos; i; i -= (i & -i))
        res += bit[i];
    return res;
}

signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        T1[u].emplace_back(v);
        T1[v].emplace_back(u);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        T2[u].emplace_back(v);
        T2[v].emplace_back(u);
    }
    calcsz(1, pa, sza, T1);
    calcsz(1, pb, szb, T2);
    doedge(sza, T1);
    doedge(szb, T2);
    t = 0;
    getorder(1, a, ta, T1);
    t = 0;
    getorder(1, b, tb, T2);
    for (int i = 1; i <= n; i++)
    {
        // compare two trees:
        // childs
        {
            int l = ta[i].F + 1, r = ta[i].F;
            int x = 0;
            for (int y : T2[i])
            {
                while (x < (int)T1[i].size() && sza[T1[i][x]] < szb[y])
                {
                    r = ta[T1[i][x]].S;
                    x++;
                }
                rect(l, r, tb[y].F, tb[y].S);
            }
        }
        // 1 root <-> 2 child
        for (int y : T2[i])
        {
            if (n - sza[i] < szb[y])
            {
                rect(1, ta[i].F - 1, tb[y].F, tb[y].S);
                rect(ta[i].S + 1, n, tb[y].F, tb[y].S);
            }
        }
        // 1 child <-> 2 root
        for (int x : T1[i])
        {
            if (sza[x] < n - szb[i])
            {
                rect(ta[x].F, ta[x].S, 1, tb[i].F - 1);
                rect(ta[x].F, ta[x].S, tb[i].S + 1, n);
            }
        }
        // 1 root <-> 2 root
        if (n - sza[i] < n - szb[i])
        {
            rect(1, ta[i].F - 1, 1, tb[i].F - 1);
            rect(1, ta[i].F - 1, tb[i].S + 1, n);
            rect(ta[i].S + 1, n, 1, tb[i].F - 1);
            rect(ta[i].S + 1, n, tb[i].S + 1, n);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto [l, r] : in[i])
            modify(l, 1), modify(r + 1, -1);
        for (auto [l, r] : out[i])
            modify(l, -1), modify(r + 1, 1);
        ans[b[i]] = query(ta[b[i]].F);
    }
    // for (int i = 1; i <= n; i++)
    //     cout << ' ' << a[i];
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << b[i] << '\n';
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
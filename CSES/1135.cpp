#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x);
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, dis[200005], x, y;
pii seg[1200005], t[200005];
vector<pii> v = {pii{0, 0}};
vector<int> e[200005];

void dfs(int k)
{
    v.pb((pii{dis[k], k}));
    t[k].F = v.size() - 1;
    for (int i : e[k])
        if (!dis[i])
        {
            dis[i] = dis[k] + 1;
            dfs(i);
            v.pb((pii{dis[k], k}));
        }
    t[k].S = v.size() - 1;
}

void modify(int l, int r, int i, int p, pii v)
{
    if (l == r)
        seg[i] = v;
    else
    {
        int mid = (l + r) / 2;
        if (p <= mid)
            modify(l, mid, i * 2, p, v);
        else
            modify(mid + 1, r, i * 2 + 1, p, v);
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}

pii query(int l, int r, int i, int a, int b)
{
    if (a <= l && r <= b)
        return seg[i];
    if (b < l || r < a)
        return pii{1e7, 1e7};
    int mid = (l + r) / 2;
    return min(query(l, mid, i * 2, a, b), query(mid + 1, r, i * 2 + 1, a, b));
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        e[x].pb(y);
        e[y].pb(x);         
    }
    dis[1] = 1;
    dfs(1);
    for (int i = 1; i < v.size(); i++)
        modify(1, v.size() - 1, 1, i, v[i]);
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        cout << dis[x] + dis[y] - query(1, v.size() - 1, 1, min(t[x].F, t[y].F), max(t[x].S, t[y].S)).F * 2 << '\n';
    }
}
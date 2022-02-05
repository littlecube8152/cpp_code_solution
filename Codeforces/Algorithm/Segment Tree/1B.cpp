#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
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

struct Q
{
    int l, r, x;
};

int n, m, seg[1200005], lazy[1200005];
vector<Q> v;

void modify(int l, int r, int i, int a, int b, int v)
{
    if (b < a)
        return;
    if (b < l || r < a)
        return;
    else if (a <= l && r <= b)
        lazy[i] = v;
    else
    {
        if (lazy[i] != 0)
            lazy[i * 2] = (lazy[i * 2 + 1] = lazy[i]);
        lazy[i] = 0;
        int mid = (l + r) / 2;
        modify(l, mid,      i * 2,      a, b, v);
        modify(mid + 1, r,  i * 2 + 1,  a, b, v);
    }
}

int query(int l, int r, int i, int p)
{
    if (l == r)
        return lazy[i];
    else
    {
        if (lazy[i] != 0)
            return lazy[i];
        int mid = (l + r) / 2;
        if (p <= mid)
            return query(l, mid, i * 2, p);
        return query(mid + 1, r, i * 2 + 1, p);
    }
}

signed main()
{
    fast;
    cin >> n >> m;
    v.resize(m);
    for (int i = 0; i < m; i++)
        cin >> v[i].l >> v[i].r >> v[i].x;
    reverse(v.begin(), v.end());
    for (auto i : v)
    {
        modify(1, n, 1, i.l, i.x - 1, i.x);
        modify(1, n, 1, i.x + 1, i.r, i.x);
    }
    for (int i = 1; i <= n; i++)
        cout << query(1, n, 1, i) << " ";
}
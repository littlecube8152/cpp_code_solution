#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, x, y;
pii seg[600005];

void modify(int l, int r, int i, int p, int v)
{
    if (l == r)
        seg[i] = pii{v + p, v - p};
    else
    {
        int mid = (l + r) / 2;
        if (p <= mid)
            modify(l, mid, i * 2, p, v);
        else
            modify(mid + 1, r, i * 2 + 1, p, v);
        seg[i] = pii{min(seg[i * 2].F, seg[i * 2 + 1].F), min(seg[i * 2].S, seg[i * 2 + 1].S)};
    }
}

pii query(int l, int r, int i, int a, int b)
{
    if (a <= l && r <= b)
        return seg[i];
    if (b < l || r < a)
        return pii{2e9, 2e9};
    int mid = (l + r) / 2;
    pii L = query(l, mid, i * 2, a, b), R = query(mid + 1, r, i * 2 + 1, a, b);
    return pii{min(L.F, R.F), min(L.S, R.S)};
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        modify(1, n, 1, i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> x >> y;
            modify(1, n, 1, x, y);
        }
        else
        {
            cin >> y;
            cout << min(query(1, n, 1, 1, y).S + y, query(1, n, 1, y, n).F - y) << '\n';
        }
    }
}
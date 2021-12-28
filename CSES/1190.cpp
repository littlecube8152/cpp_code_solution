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

struct block
{
    ll l, r, m, t;
    ll getval(){
        return max({l, r, m});
    }
} seg[600005];

int n, m, x, y, arr[200005];

block merge(block L, block R)
{
    return block{max(L.l, L.t + R.l), max(L.r + R.t, R.r), max({L.m, R.m, L.r + R.l}), L.t + R.t};
}

void modify(int l, int r, int i, int p, int v)
{
    if (l == r)
        seg[i] = {max(0, v), max(0, v), max(0, v), v};
    else
    {
        int mid = (l + r) / 2;
        if (p <= mid)
            modify(l, mid, i * 2, p, v);
        else
            modify(mid + 1, r, i * 2 + 1, p, v);
        seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
    }
}

block query(int l, int r, int i, int a, int b)
{
    if (a <= l && r <= b)
        return seg[i];
    if (b < l || r < a)
        return {0, 0, 0, 0};
    int mid = (l + r) / 2;
    return merge(query(l, mid, i * 2, a, b), query(mid + 1, r, i * 2 + 1, a, b));
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
        cin >> x >> y;
        modify(1, n, 1, x, y);
        cout << query(1, n, 1, 1, n).getval() << '\n';
    }
}
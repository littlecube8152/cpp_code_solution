#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, arr[200005], seg[600005];

int build(int l, int r, int i)
{
    if (l == r)
        return seg[i] = arr[l];
    int mid = (l + r) / 2;
    return seg[i] = min(build(l, mid, i * 2), build(mid + 1, r, i * 2 + 1));
}

void modify(int l, int r, int i, int pos, int val)
{
    if (l == r)
        seg[i] = val;
    else
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
            modify(l, mid, i * 2, pos, val);
        else
            modify(mid + 1, r, i * 2 + 1, pos, val);
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}

int query(int l, int r, int i, int a, int b)
{
    if (a <= l && r <= b)
        return seg[i];
    if (b < l || r < a)
        return 100000000000;
    int mid = (l + r) / 2;
    return min(query(l, mid, i * 2, a, b), query(mid + 1, r, i * 2 + 1, a, b));
}
signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, n, 1);
    for (int i = 1; i <= q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1)
            modify(1, n, 1, b, c);
        else
            cout << query(1, n, 1, b, c) << '\n';
        
    }
}
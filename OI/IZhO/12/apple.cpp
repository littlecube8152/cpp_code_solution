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

int q, seg[6000000], _left[6000000], _right[6000000], pointer = 1, lazy[60000000], c, d, x, y;

int getval(int l, int r, int i)
{
    return max(seg[i], lazy[i] * (r - l + 1));
}

void modify(int l, int r, int i, int a, int b, int v)
{

    if (b < l || r < a)
        return;
    if ((a <= l && r <= b) || lazy[i])
        lazy[i] = v;
    else
    {
        int mid = (l + r) / 2;
        if (_left[i] == 0)
            _left[i] = ++pointer;
        if (_right[i] == 0)
            _right[i] = ++pointer;

        modify(l, mid, _left[i], a, b, v);
        modify(mid + 1, r, _right[i], a, b, v);

        seg[i] = getval(l, mid, _left[i]) + getval(mid + 1, r, _right[i]);
        //cout << "Pull " << i << "  left=" << seg[_left[i]] << " " << lazy[_left[i]] << " right=" << getval(mid + 1, r, _right[i]) << '\n';
    }
    //cout << "Block " << l << "->" << r << " Seg=" << seg[i] << " Lazy=" << lazy[i] << '\n';
}

int query(int l, int r, int i, int a, int b)
{
    //cout << "Block " << l << "->" << r << " Seg=" << seg[i] << " Lazy=" << lazy[i] << '\n';
    if (b < l || r < a)
        return 0;
    if (a <= l && r <= b)
        return getval(l, r, i);
    else
    {
        int mid = (l + r) / 2;
        if (_left[i] == 0)
            _left[i] = ++pointer;
        lazy[_left[i]] = max(lazy[_left[i]], lazy[i]);

        if (_right[i] == 0)
            _right[i] = ++pointer;
        lazy[_right[i]] = max(lazy[_right[i]], lazy[i]);

        lazy[i] = 0;
        seg[i] = getval(l, mid, _left[i]) + getval(mid + 1, r, _right[i]);
        return query(l, mid, _left[i], a, b) + query(mid + 1, r, _right[i], a, b);
    }
}

signed main()
{
    fast;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> d >> x >> y;
        if (d == 1)
        {
            int res = query(1, 2000000000, 1, x + c, y + c);
            c = res;
            cout << res << '\n';
        }
        else
            modify(1, 2000000000, 1, x + c, y + c, 1);
    }
}
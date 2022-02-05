/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

int n, q;
ll arr[200005], seg[800005], a[800005], b[800005];

void push(int i, ll l, ll r)
{
    ll mid = (l + r) / 2;
    a[i * 2] += a[i];
    a[i * 2 + 1] += a[i];
    b[i * 2] += b[i];
    b[i * 2 + 1] += b[i] + (mid - l + 1) * a[i];
    seg[i] += (a[i] * 1 + b[i] + a[i] * (r - l + 1) + b[i]) * (r - l + 1) / 2;
    a[i] = b[i] = 0;
}

ll getval(int i, ll l, ll r)
{
    return seg[i] + (a[i] * 1 + b[i] + a[i] * (r - l + 1) + b[i]) * (r - l + 1) / 2;
}

void modify(ll ml, ll mr, ll A, ll B, ll i = 1, ll l = 1, ll r = n)
{
    if (mr < l || r < ml)
        return;
    if (ml <= l && r <= mr)
    {
        a[i] += A;
        b[i] += B + (l - ml) * A;
        return;
    }
    ll mid = (l + r) / 2;
    push(i, l, r);
    modify(ml, mr, A, B, i * 2, l, mid);
    modify(ml, mr, A, B, i * 2 + 1, mid + 1, r);
    seg[i] = getval(i * 2, l, mid) + getval(i * 2 + 1, mid + 1, r);
}

ll query(ll ql, ll qr, ll i = 1, ll l = 1, ll r = n)
{
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return getval(i, l, r);
    ll mid = (l + r) / 2;
    push(i, l, r);
    return query(ql, qr, i * 2, l, mid) + query(ql, qr, i * 2 + 1, mid + 1, r);
}

void debug(ll i = 1, ll l = 1, ll r = n)
{
    
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        modify(i, i, 0, arr[i]);
    }

    for (int i = 1; i <= q; i++)
    {

        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1)
            modify(a, b, 1, 0);
        else
            cout << query(a, b) << '\n';
        debug();
    }
}
/*
5 3
4 2 3 1 7
2 1 5
1 1 3
2 2 5
*/

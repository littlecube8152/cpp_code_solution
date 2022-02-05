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
ll arr[200005], seg[800005], lazy[800005];

void modify(int ml, int mr, ll val, int i = 1, int l = 1, int r = n)
{
    if (mr < l || r < ml)
        return;
    if (ml <= l && r <= mr)
    {
        lazy[i] += val;
        return;
    }
    int mid = (l + r) / 2;
    seg[i] += lazy[i];
    lazy[i * 2] += lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
    modify(ml, mr, val, i * 2, l, mid);
    modify(ml, mr, val, i * 2 + 1, mid + 1, r);
    seg[i] = max(seg[i * 2] + lazy[i * 2], seg[i * 2 + 1] + lazy[i * 2 + 1]);
}

ll query(int ql, int qr, int i = 1, int l = 1, int r = n)
{
    if (qr < l || r < ql)
        return -1e18;
    if (ql <= l && r <= qr)
        return seg[i] + lazy[i];
    int mid = (l + r) / 2;
    seg[i] += lazy[i];
    lazy[i * 2] += lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
    return max(query(ql, qr, i * 2, l, mid), query(ql, qr, i * 2 + 1, mid + 1, r));
}

signed main()
{
    fast;
    cin >> n >> q;
    ll a, pre = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre += arr[i];
        modify(i, i, pre);
    }
    for (int i = 1; i <= q; i++)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1)
        {
            modify(a, n, b - arr[a]);
            arr[a] = b;
        }
        else
            cout << max(0LL, query(a, b) - (a == 1 ? 0 : query(a - 1, a - 1))) << '\n';
    }
}

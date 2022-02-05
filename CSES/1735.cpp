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
ll arr[200005], seg[800005], lazy[800005], lazy2[800005], ans[200005], qdx = 0;
bool reset[800005];
vector<pair<pii, int>> queries;
vector<pll> mono;

void push(int i, ll l, ll r)
{
    if (reset[i])
    {
        reset[i * 2] = reset[i * 2 + 1] = 1;
        lazy2[i * 2] = lazy2[i * 2 + 1] = lazy2[i];
        seg[i] = (r - l + 1) * lazy2[i];
        lazy[i] = lazy2[i] = reset[i] = 0;
    }
    else
    {
        if (reset[i * 2])
            lazy2[i * 2] += lazy[i];
        else
            lazy[i * 2] += lazy[i];
        if (reset[i * 2 + 1])
            lazy2[i * 2 + 1] += lazy[i];
        else
            lazy[i * 2 + 1] += lazy[i];
        seg[i] += lazy[i] * (r - l + 1);
        lazy[i] = 0;
    }
}

ll getval(int i, ll l, ll r)
{
    if (reset[i])
        return lazy2[i] * (r - l + 1);
    else
        return seg[i] + lazy[i] * (r - l + 1);
}

void modify(ll ml, ll mr, ll val, ll i = 1, ll l = 1, ll r = n)
{
    if (mr < l || r < ml)
        return;
    if (ml <= l && r <= mr)
    {
        if (reset[i])
            lazy2[i] += val;
        else
            lazy[i] += val;
        return;
    }
    ll mid = (l + r) / 2;
    push(i, l, r);
    modify(ml, mr, val, i * 2, l, mid);
    modify(ml, mr, val, i * 2 + 1, mid + 1, r);
    seg[i] = getval(i * 2, l, mid) + getval(i * 2 + 1, mid + 1, r);
}

void modify2(ll ml, ll mr, ll val, ll i = 1, ll l = 1, ll r = n)
{
    if (mr < l || r < ml)
        return;
    if (ml <= l && r <= mr)
    {
        reset[i] = 1;
        lazy2[i] = val;
        return;
    }
    ll mid = (l + r) / 2;
    push(i, l, r);
    modify2(ml, mr, val, i * 2, l, mid);
    modify2(ml, mr, val, i * 2 + 1, mid + 1, r);
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
    //cout << "(" << l << ", " << r << ") seg " << seg[i] << "  lazy " << lazy[i] << "  lazy2 " << lazy2[i] << "  reset " << reset[i] << '\n';
    //if (l != r)
    //{
    //    ll mid = (l + r) / 2;
    //    debug(i * 2, l, mid);
    //    debug(i * 2 + 1, mid + 1, r);
    //}
}

signed main()
{
    //fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        modify2(i, i, arr[i]);
    }

    for (int i = 1; i <= q; i++)
    {
        debug();
        int type, a, b, x;
        cin >> type >> a >> b;
        if (type == 1)
        {
            cin >> x;
            modify(a, b, x);
        }
        else if (type == 2)
        {
            cin >> x;
            modify2(a, b, x);
        }
        else
            cout << query(a, b) << '\n';
    }
}

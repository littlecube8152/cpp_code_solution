/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct line
{
    ll a, b;
    ll val(ll x)
    {
        return a * x + b;
    }
    line(ll a, ll b) : a(a), b(b){};
    line() : a(0), b(1e18){};
} seg[4000005];

void modify(int i, int l, int r, line fx)
{
    if (l == r)
    {
        if (fx.val(l) < seg[i].val(l))
            seg[i] = fx;
        return;
    }
    int mid = (l + r) / 2;
    if (fx.val(mid) < seg[i].val(mid))
        swap(seg[i], fx);

    if (fx.a > seg[i].a)
        modify(i * 2, l, mid, fx);
    else
        modify(i * 2 + 1, mid + 1, r, fx);
}

ll query(int i, int l, int r, ll p)
{
    if (l == r)
        return seg[i].val(p);

    int mid = (l + r) / 2;
    if (p <= mid)
        return min(query(i * 2, l, mid, p), seg[i].val(p));
    else
        return min(query(i * 2 + 1, mid + 1, r, p), seg[i].val(p));
}

ll N, C, dp[200005], h[200005];

signed main()
{
    cin >> N >> C;
    for (int i = 1; i <= N; i++)
        cin >> h[i];

    modify(1, 1, 1000000, line(-2 * h[1], h[1] * h[1]));
    for (int i = 2; i <= N; i++)
    {
        dp[i] = query(1, 1, 1000000, h[i]) + h[i] * h[i] + C;
        modify(1, 1, 1000000, line(-2 * h[i], dp[i] + h[i] * h[i]));
        //cout << dp[i] << " ";
    }
    cout << dp[N] << '\n';
}

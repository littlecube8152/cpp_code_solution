/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;
const int C = 1e6;
ll N, dp[200005], x, s[200005], f[200005];
pll seg[2 * C + 5];

void modify(pll val, int i = 1, ll L = 1, ll R = C)
{
    int mid = (L + R) / 2;
    if (val.F * mid + val.S <= seg[i].F * mid + seg[i].S)
        swap(seg[i], val);
    if(L != R)
    {
        if (val.F > seg[i].F)
            modify(val, i + 1, L, mid);
        else if (val.F < seg[i].F)
            modify(val, i + 2 * (mid - L + 1), mid + 1, R);
    }
}

ll query(ll val, int i = 1, ll L = 1, ll R = C)
{
    int mid = (L + R) / 2;
    if(L == R)
        return seg[i].F * val + seg[i].S;
    if (val <= mid)
        return min(seg[i].F * val + seg[i].S, query(val, i + 1, L, mid));
    else
        return min(seg[i].F * val + seg[i].S, query(val, i + 2 * (mid - L + 1), mid + 1, R));
}

signed main()
{
    fast;
    cin >> N >> x;
    for (int i = 1; i <= 2 * C; i++)
        seg[i] = {0, 1e18};
    for (int i = 1; i <= N; i++)
        cin >> s[i];
    for (int i = 1; i <= N; i++)
        cin >> f[i];
    modify({x, 0});
    for (int i = 1; i <= N; i++)
    {
        dp[i] = query(s[i]);
        modify({f[i], dp[i]});
    }
    cout << dp[N] << '\n';
}

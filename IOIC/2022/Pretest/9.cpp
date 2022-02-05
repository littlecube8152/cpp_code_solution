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

ll n, m, dp[100005];
pll rp[100005], lp[100005];

void DP(int L, int R, int tL, int tR)
{
    if (R < L)
        return;
    int mid = (L + R) / 2, tmid = tL;
    for (int i = tL; i <= tR; i++)
        if ((rp[mid].F - lp[i].F) * (rp[mid].S - lp[i].S) > dp[mid])
            dp[mid] = (rp[mid].F - lp[i].F) * (rp[mid].S - lp[i].S), tmid = i;
            
    if (L != R)
    {
        DP(L, mid - 1, tL, tmid);
        DP(mid + 1, R, tmid, tR);
    }
}

signed main()
{
    fast;
    cin >> n;
    n /= 2;
    ll xoff, yoff;
    cin >> xoff;
    rp[1] = {xoff, 0};
    for (int i = 2; i <= n; i++)
    {
        cin >> yoff >> xoff;
        rp[i] = {rp[i - 1].F + xoff, rp[i - 1].S - yoff};
    }
    cin >> yoff;
    cin >> m;
    m /= 2;
    cin >> yoff;
    lp[1] = {0, -yoff};
    for (int i = 2; i <= m; i++)
    {
        cin >> xoff >> yoff;
        lp[i] = {lp[i - 1].F + xoff, lp[i - 1].S - yoff};
    }
    cin >> xoff;
    DP(1, n, 1, m);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
}

/*
6
5 3 4 3 3 3
4
5 4 4 8
*/
/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll ans, dp[3002][3002][4], vis[3002][3002][4];
pll a, b, c;
const int cent = 150, bound = 30;

void solve()
{
    ans = 0;
    cin >> a.F >> a.S >> b.F >> b.S >> c.F >> c.S;
    pll p = {a.F + b.F + c.F - 1, a.S + b.S + c.S - 1};

    ll x = abs(p.F) / 3 * 2 + (abs(p.F) % 3 >= 1);
    ll y = abs(p.S) / 3 * 2 + (abs(p.S) % 3 >= 1);
    
    cout << max(x, y) + (p.F == p.S && max(abs(p.F), abs(p.S)) >= 2 ? 1 : 0) << '\n';
}

struct pos
{
    int x, y, o;
};

pos spin(int ori, pos p)
{
    if (ori == 0)
        return p;
    else if (ori == 1)
        return {-p.y, p.x, p.o};
    else if (ori == 2)
        return {-p.x, -p.y, p.o};
    return {p.y, -p.x, p.o};
}


signed main()
{
    //fast;
    int T;
    cin >> T;
    while (T-->0)
        solve();
}

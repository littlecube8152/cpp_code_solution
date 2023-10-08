/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, y;
pll p[1000005];

ll ceil(ll a, ll b)
{
    // ceil(a/b)
    if (b < 0)
        a *= -1, b *= -1;
    return (a < 0 ? a / b : (a - 1) / b + 1);
}

ll floor(ll a, ll b)
{
    // floor(a/b)
    if (b < 0)
        a *= -1, b *= -1;
    return (a < 0 ? (a + 1) / b - 1 : a / b);
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].F >> p[i].S;
    if (p[3].S > p[2].S)
    {
        for (int i = 1; i <= n; i++)
            p[i].F = -p[i].F, p[i].S = -p[i].S;
    }
    y = p[1].S;
    ll l = p[1].F, r = p[2].F;
    for (int i = 3; i + 1 <= n; i++)
        if (p[i].S > p[i + 1].S)
        {
            r = min(r, p[i].F + floor((p[i + 1].F - p[i].F) * (y - p[i].S), p[i + 1].S - p[i].S));
            //cerr << 'r' << r << '\n';
        }
        else if (p[i].S < p[i + 1].S)
        {
            l = max(l, p[i].F + ceil((p[i + 1].F - p[i].F) * (y - p[i].S), p[i + 1].S - p[i].S));
            //cerr << 'l' << l << '\n';
        }
        else if (p[i].F < p[i + 1].F)
        {
            cout << 0 << '\n';
            return 0;
        }
    cout << max(0LL, r - l + 1) << '\n';
}

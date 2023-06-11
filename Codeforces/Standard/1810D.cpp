/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

pll bound(ll a, ll b, ll n)
{
    if (n == 1)
        return pll(0, a);
    return pll(a + (a - b) * (n - 2) + 1, a + (a - b) * (n - 1));
}

signed main()
{
    fast;

    int t;
    cin >> t;
    while (t--)
    {
        ll q, t, a, b, n, l = 0, r = 2e18;
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            cin >> t >> a >> b;
            if (t == 1)
            {
                cin >> n;
                auto [ql, qr] = bound(a, b, n);
                if (qr < l || r < ql)
                    cout << 0 << " \n"[i == q];
                else
                {
                    l = max(l, ql), r = min(r, qr);
                    cout << 1 << " \n"[i == q];
                }
            }
            else
            {
                ll aL = (l <= a ? 1 : (l - b - 1) / (a - b) + 1),
                   aR = (r <= a ? 1 : (r - b - 1) / (a - b) + 1);
                if (aL < aR)
                    cout << -1 << " \n"[i == q];
                else
                    cout << aL << " \n"[i == q];
            }
        }
    }
}

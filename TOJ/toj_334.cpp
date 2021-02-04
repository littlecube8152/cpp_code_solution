#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll fastpow(ll n)
{
    if (n == 0)
        return 1;
    if (n % 2)
        return 3 * fastpow(n - 1);
    ll k = fastpow(n / 2);
    return k * k;
}

ll dc(ll x1, ll y1, ll x2, ll y2)
{

    ll lbx = 0, lby = 0;
    while ((1 << (lbx + 1)) < x2)
        lbx++;
    while ((1 << (lby + 1)) < y2)
        lby++;
    cout << "D&C " << x1 << " " << y1 << "    " << x2 << " " << y2 << "     " << lbx << " " << lby << "\n";
    if (x1 == 1 && x2 == (1 << (lbx + 1)) && y1 == 1 && y2 == (1 << (lbx + 1)))
        return fastpow(lbx + 1);

    if (x1 == 1 && x2 == 1 && y1 == 1 && y2 == 1)
        return 1;

    if (x1 > (1 << (lbx)) && y1 > (1 << (lby)))
        return 0;

    if (x1 > (1 << (lbx)))
        return dc(x1 - (1 << (lbx)), y1, x2 - (1 << (lbx)), (1 << (lby)));

    if (y1 > (1 << (lby)))
        return dc(x1, y1 - (1 << (lby)), (1 << (lbx)), y2 - (1 << (lby)));

    if (lbx > lby)
        return dc(x1, y1, (1 << (lbx)), y2) +
               dc(1, y1, max(1LL, x2 - (1 << (lbx))), y2);

    if (lby > lbx)
        return dc(x1, y1, x2, (1 << (lby))) +
               dc(x1, 1, x2, max(1LL, y2 - (1 << (lby))));

    return dc(x1, y1, (1 << (lbx)), (1 << (lby))) +
           dc(1, y1, max(1LL, x2 - (1 << (lbx))), (1 << (lby))) +
           dc(x1, 1, (1 << (lbx)), max(1LL, y2 - (1 << (lby))));
}

signed main()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << dc(x1, y1, x2, y2) << '\n';
}

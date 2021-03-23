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

map<tuple<ll, ll, ll, ll>, ll> mp;
map<ll, ll> fstp;

ll fastpow(ll n)
{
    if (n == 0)
        return 1;
    if (fstp[n] == 0)
    {
        if (n % 2)
            fstp[n] = 3 * fastpow(n - 1);
        else
            fstp[n] = fastpow(n / 2) * fastpow(n / 2);
    }
    return fstp[n];
}

ll dc(ll x1, ll y1, ll x2, ll y2)
{
    if (x2 < x1 || y2 < y1)
        return 0;

    ll lbx = log2(x2) - 1, lby = log2(y2) - 1;
    while ((1 << lbx) < x2)
        lbx++;
    while ((1 << lby) < y2)
        lby++;

    if (x1 == 1 && x2 == (1 << (lbx)) && y1 == 1 && y2 == (1 << (lbx)))
        mp[make_tuple(x1, y1, x2, y2)] = fastpow(lbx);

    if (mp[make_tuple(x1, y1, x2, y2)] == 0)
    {

        if (lbx > lby)
            mp[make_tuple(x1, y1, x2, y2)] = dc(x1, y1, (1 << (lbx - 1)), y2) +
                                             dc(max(1LL, x1 - (1 << (lbx - 1))), y1, x2 - (1 << (lbx - 1)), y2);

        else if (lby > lbx)
            mp[make_tuple(x1, y1, x2, y2)] = dc(x1, y1, x2, (1 << (lby - 1))) +
                                             dc(x1, max(1LL, y1 - (1 << (lby - 1))), x2, y2 - (1 << (lby - 1)));

        else
            mp[make_tuple(x1, y1, x2, y2)] = dc(x1, y1, (1 << (lbx - 1)), (1 << (lby - 1))) +
                                             dc(max(1LL, x1 - (1 << (lbx - 1))), y1, x2 - (1 << (lbx - 1)), (1 << (lby - 1))) +
                                             dc(x1, max(1LL, y1 - (1 << (lby - 1))), (1 << (lbx - 1)), y2 - (1 << (lby - 1)));
        //cout << "cal++      ";
    }
    return mp[make_tuple(x1, y1, x2, y2)];
}

signed main()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << dc(x1, y1, x2, y2) << '\n';
}

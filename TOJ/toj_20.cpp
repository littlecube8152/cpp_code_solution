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

ll gcd(ll a, ll b)
{
    if (min(a, b) == 0)
        return max(a, b);
    return gcd(b % a, a);
}

signed main()
{
    ll x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        if (x1 == x2 && y1 == y2)
            cout << 1 << '\n';
        else if (x1 == x2)
            cout << abs(y1 - y2) + 1 << '\n';
        else if (y1 == y2)
            cout << abs(x1 - x2) + 1 << '\n';
        else
            cout << abs(x1 - x2) + abs(y1 - y2) + gcd(abs(x1 - x2), abs(y1 - y2)) << '\n';
    }
}

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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

pll operator+(pll p1, pll p2)
{
    return pll(p1.F + p2.F, p1.S + p2.S);
}
pll operator-(pll p1, pll p2)
{
    return pll(p1.F - p2.F, p1.S - p2.S);
}
ll det(ll a, ll b, ll c, ll d)
{
    return a * d - b * c;
}
ll det(pll p1, pll p2)
{
    return det(p1.F, p1.S, p2.F, p2.S);
}
ll dot(pll a, pll b)
{
    return a.F * b.F + a.S * b.S;
}
ll cross(pll p, pll a, pll b)
{
    return det(a - p, b - p);
}
int ori(pll p, pll a, pll b)
{
    ll d = cross(p, a, b);
    return d < 0 ? -1 : (d == 0 ? 0 : 1);
}
bool intersect(pll p1, pll p2, pll p3, pll p4)
{
    ll s123 = ori(p1, p2, p3), s124 = ori(p1, p2, p4),
       s341 = ori(p3, p4, p1), s342 = ori(p3, p4, p2),
       o123 = dot(p1 - p3, p2 - p3), o124 = dot(p1 - p4, p2 - p4),
       o341 = dot(p3 - p1, p4 - p1), o342 = dot(p3 - p2, p4 - p2);
    if (s123 == 0 && s124 == 0)
        return o123 <= 0 || o124 <= 0 || o341 <= 0 || o342 <= 0;
    return s123 * s124 <= 0 && s341 * s342 <= 0;
}

int n;
pll p[1001];
ll A, B;

signed main()
{
    fast;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 0; i < n; i++)
    {
        A += cross(pll(0, 0), p[i], p[(i + 1) % n]);
        pll vec = p[(i + 1) % n] - p[i];
        B += (vec == pll(0, 0) ? 0 : __gcd(abs(vec.F), abs(vec.S)));
    }
    A = abs(A);
    cout << (A - B + 2) / 2 << ' ' << B << '\n';
}

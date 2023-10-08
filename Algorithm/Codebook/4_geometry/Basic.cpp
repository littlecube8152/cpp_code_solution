#include <bits/stdc++.h>
using namespace std;
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ll long long
#define F first
#define S second

pll operator+(pll p1, pll p2)
{ return pll(p1.F + p2.F, p1.S + p2.S); }
pll operator-(pll p1, pll p2)
{ return pll(p1.F - p2.F, p1.S - p2.S); }
pdd operator*(pdd p, double d)
{ return pdd(p.F * d, p.S * d); }
pdd operator/(pdd p, double d)
{ return pdd(p.F / d, p.S / d); }
ll det(ll a, ll b, ll c, ll d)
{ return a * d - b * c; }
ll det(pll p1, pll p2)
{ return det(p1.F, p1.S, p2.F, p2.S); }
ll dot(pll a, pll b)
{ return a.F * b.F + a.S * b.S; }
ll cross(pll p, pll a, pll b)
{ return det(a - p, b - p); }
int ori(pll p, pll a, pll b)
{
    ll d = cross(p, a, b);
    return d < 0 ? -1 : (d == 0 ? 0 : 1);
}
bool btw(pll p, pll a, pll b)
{
    return ori(p, a, b) == 0 && dot(a - p, b - p) <= 0;
}
bool intersect(pll p1, pll p2, pll p3, pll p4)
{
    ll s123 = ori(p1, p2, p3), s124 = ori(p1, p2, p4),
       s341 = ori(p3, p4, p1), s342 = ori(p3, p4, p2);
    if (s123 == 0 && s124 == 0)
        return btw(p3, p1, p2) || btw(p4, p1, p2) || 
               btw(p1, p3, p4) || btw(p2, p3, p4);
    return s123 * s124 <= 0 && s341 * s342 <= 0;
}
pdd intersection(pll p1, pll p2, pll p3, pll p4)
{
    double a123 = cross(p1, p2, p3),
           a124 = -cross(p1, p2, p4);
    return (p4 * a123 + p3 * a124) / (a123 + a124);
}
ll dis2(pll p, pll q)
{ return dot(p - q, p - q); }

signed main()
{
    pdd p = intersection(pll(0, 0), pll(3, 3), pll(-1, 2), pll(4, -1));
    cout << p.F << ' ' << p.S;
}